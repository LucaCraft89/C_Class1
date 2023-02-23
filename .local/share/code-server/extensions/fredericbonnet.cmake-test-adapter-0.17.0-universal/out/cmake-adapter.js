"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.CmakeAdapter = void 0;
const tslib_1 = require("tslib");
const vscode = require("vscode");
const path = require("path");
const os = require("os");
const cmake_runner_1 = require("./cmake-runner");
const ROOT_SUITE_ID = '*';
const SUITE_SUFFIX = '*';
class CmakeAdapter {
    constructor(workspaceFolder, log) {
        this.workspaceFolder = workspaceFolder;
        this.log = log;
        this.disposables = [];
        this.ctestPath = '';
        this.cmakeTests = [];
        this.state = 'idle';
        this.testsEmitter = new vscode.EventEmitter();
        this.testStatesEmitter = new vscode.EventEmitter();
        this.retireEmitter = new vscode.EventEmitter();
        this.autorunEmitter = new vscode.EventEmitter();
        this.log.info('Initializing CMake test adapter');
        this.disposables.push(this.testsEmitter);
        this.disposables.push(this.testStatesEmitter);
        this.disposables.push(this.autorunEmitter);
    }
    get tests() {
        return this.testsEmitter.event;
    }
    get testStates() {
        return this.testStatesEmitter.event;
    }
    get retire() {
        return this.retireEmitter.event;
    }
    get autorun() {
        return this.autorunEmitter.event;
    }
    load() {
        return tslib_1.__awaiter(this, void 0, void 0, function* () {
            if (this.state !== 'idle')
                return;
            this.state = 'loading';
            this.log.info('Loading CMake tests');
            this.testsEmitter.fire({ type: 'started' });
            try {
                const suite = yield this.loadTestSuite();
                this.testsEmitter.fire({
                    type: 'finished',
                    suite,
                });
            }
            catch (e) {
                this.testsEmitter.fire({
                    type: 'finished',
                    errorMessage: `${e}`,
                });
            }
            this.state = 'idle';
        });
    }
    run(tests) {
        return tslib_1.__awaiter(this, void 0, void 0, function* () {
            if (this.state !== 'idle')
                return;
            this.state = 'running';
            this.log.info(`Running CMake tests ${JSON.stringify(tests)}`);
            this.testStatesEmitter.fire({
                type: 'started',
                tests,
            });
            const runAll = tests.length == 1 && tests[0] === ROOT_SUITE_ID;
            if (runAll) {
                try {
                    this.testStatesEmitter.fire({
                        type: 'suite',
                        suite: ROOT_SUITE_ID,
                        state: 'running',
                    });
                    yield this.runTests([]);
                    this.testStatesEmitter.fire({
                        type: 'suite',
                        suite: ROOT_SUITE_ID,
                        state: 'completed',
                    });
                }
                catch (e) {
                    this.testStatesEmitter.fire({
                        type: 'suite',
                        suite: ROOT_SUITE_ID,
                        state: 'errored',
                        message: `${e}`,
                    });
                }
            }
            else {
                try {
                    yield this.runTests(tests);
                }
                catch (e) {
                }
            }
            this.testStatesEmitter.fire({ type: 'finished' });
            this.state = 'idle';
        });
    }
    debug(tests) {
        return tslib_1.__awaiter(this, void 0, void 0, function* () {
            this.log.info(`Debugging CMake tests ${JSON.stringify(tests)}`);
            try {
                for (const id of tests) {
                    yield this.debugTest(id);
                }
            }
            catch (e) {
            }
        });
    }
    cancel() {
        if (this.state !== 'running')
            return;
        if (this.currentTestProcess)
            cmake_runner_1.cancelCmakeTestProcess(this.currentTestProcess);
        this.state = 'cancelled';
    }
    dispose() {
        this.cancel();
        for (const disposable of this.disposables) {
            disposable.dispose();
        }
        this.disposables = [];
    }
    loadTestSuite() {
        return tslib_1.__awaiter(this, void 0, void 0, function* () {
            try {
                const [buildDir, buildConfig, extraCtestLoadArgs, suiteDelimiter, testFileVar, testLineVar,] = yield this.getConfigStrings([
                    'buildDir',
                    'buildConfig',
                    'extraCtestLoadArgs',
                    'suiteDelimiter',
                    'testFileVar',
                    'testLineVar',
                ]);
                const dir = path.resolve(this.workspaceFolder.uri.fsPath, buildDir);
                this.ctestPath = cmake_runner_1.getCtestPath(dir);
                this.cmakeTests = yield cmake_runner_1.loadCmakeTests(this.ctestPath, dir, buildConfig, extraCtestLoadArgs);
                const rootSuite = {
                    type: 'suite',
                    id: ROOT_SUITE_ID,
                    label: 'CMake',
                    children: [],
                };
                if (!suiteDelimiter) {
                    rootSuite.children = this.cmakeTests.map((test) => (Object.assign({ type: 'test', id: test.name, label: test.name }, getTestFileInfo(test, testFileVar, testLineVar))));
                    return rootSuite;
                }
                else {
                    for (let test of this.cmakeTests) {
                        const path = test.name.split(suiteDelimiter);
                        const testName = path.pop() || 'undefined';
                        let suite = rootSuite;
                        let currentId = '';
                        for (let name of path) {
                            currentId += name + suiteDelimiter;
                            let childSuite = suite.children.find((item) => item.type == 'suite' && item.id === currentId + SUITE_SUFFIX);
                            if (!childSuite) {
                                childSuite = {
                                    type: 'suite',
                                    id: currentId + SUITE_SUFFIX,
                                    label: name,
                                    children: [],
                                    tooltip: currentId.substr(0, currentId.length - suiteDelimiter.length),
                                };
                                suite.children.push(childSuite);
                            }
                            suite = childSuite;
                        }
                        const testInfo = Object.assign({ type: 'test', id: test.name, label: testName, description: test.name, tooltip: test.name }, getTestFileInfo(test, testFileVar, testLineVar));
                        suite.children.push(testInfo);
                    }
                    return rootSuite;
                }
            }
            catch (e) {
                if (e instanceof cmake_runner_1.CacheNotFoundError && !(yield this.isCmakeWorkspace())) {
                    this.log.info(`Workspace does not seem to contain CMake project files, ignoring tests`);
                    return;
                }
                else {
                    throw e;
                }
            }
        });
    }
    runTests(tests) {
        return tslib_1.__awaiter(this, void 0, void 0, function* () {
            if (this.state === 'cancelled') {
                this.retireEmitter.fire({ tests });
                return;
            }
            try {
                const options = yield this.getRunOptions();
                const [suiteDelimiter, errorPattern] = yield this.getConfigStrings([
                    'suiteDelimiter',
                    'errorPattern',
                ]);
                const errorPatternRe = new RegExp(errorPattern);
                const testIndexes = this.getTestIndexes(tests, suiteDelimiter);
                this.currentTestProcess = cmake_runner_1.scheduleCmakeTestProcess(testIndexes, options);
                const outputs = [];
                const decorations = [];
                yield cmake_runner_1.executeCmakeTestProcess(this.currentTestProcess, (event) => {
                    var _a;
                    switch (event.type) {
                        case 'start':
                            this.testStatesEmitter.fire({
                                type: 'test',
                                test: event.name,
                                state: 'running',
                            });
                            break;
                        case 'output':
                            if (!outputs[event.index])
                                outputs[event.index] = [];
                            outputs[event.index].push(event.line);
                            const matches = (_a = event.text) === null || _a === void 0 ? void 0 : _a.match(errorPatternRe);
                            if (matches === null || matches === void 0 ? void 0 : matches.groups) {
                                const { file, line, severity, message } = matches.groups;
                                if (!decorations[event.index])
                                    decorations[event.index] = [];
                                decorations[event.index].push({
                                    file,
                                    line: Number.parseInt(line) - 1,
                                    message: severity ? `${severity}: ${message}` : message,
                                });
                            }
                            break;
                        case 'end':
                            let message = outputs[event.index]
                                ? outputs[event.index].join('\n')
                                : undefined;
                            this.testStatesEmitter.fire({
                                type: 'test',
                                test: event.name,
                                state: event.state,
                                message,
                                decorations: decorations[event.index],
                            });
                            break;
                    }
                });
            }
            finally {
                this.currentTestProcess = undefined;
            }
        });
    }
    getRunOptions() {
        return tslib_1.__awaiter(this, void 0, void 0, function* () {
            const [buildDir, buildConfig, extraCtestRunArgs] = yield this.getConfigStrings([
                'buildDir',
                'buildConfig',
                'extraCtestRunArgs',
            ]);
            const extraCtestEnvVars = yield this.getConfigObject('extraCtestEnvVars');
            const parallelJobs = this.getParallelJobs();
            return {
                ctestPath: this.ctestPath,
                cwd: path.resolve(this.workspaceFolder.uri.fsPath, buildDir),
                env: mergeVariablesIntoProcessEnv(extraCtestEnvVars),
                parallelJobs,
                buildConfig,
                extraArgs: extraCtestRunArgs,
            };
        });
    }
    getTestIndexes(ids, suiteDelimiter) {
        if (ids.length === 0) {
            return [];
        }
        let tests = [];
        const allTests = this.cmakeTests.map((test) => test.name);
        for (const id of ids) {
            if (suiteDelimiter && id.endsWith(suiteDelimiter + SUITE_SUFFIX)) {
                tests.push(...allTests.filter((test) => test.startsWith(id.substr(0, id.length - SUITE_SUFFIX.length))));
            }
            else {
                tests.push(id);
            }
        }
        return tests.map((id) => this.cmakeTests.findIndex((test) => test.name === id) + 1);
    }
    debugTest(id) {
        return tslib_1.__awaiter(this, void 0, void 0, function* () {
            if (id === ROOT_SUITE_ID) {
                return;
            }
            const test = this.cmakeTests.find((test) => test.name === id);
            if (!test) {
                return;
            }
            this.log.info(`Debugging CMake test ${id}`);
            const disposables = [];
            try {
                const extraCtestEnvVars = yield this.getConfigObject('extraCtestEnvVars');
                const [debugConfig] = yield this.getConfigStrings(['debugConfig']);
                const defaultConfig = this.getDefaultDebugConfiguration();
                const _a = cmake_runner_1.getCmakeTestDebugConfiguration(test), { env } = _a, debuggedTestConfig = tslib_1.__rest(_a, ["env"]);
                const mergeEnvironments = (environment) => mergeVariablesIntoDebugEnv(mergeVariablesIntoDebugEnv(environment, extraCtestEnvVars), env);
                const mergeConfigs = (_a) => {
                    var { environment = [] } = _a, config = tslib_1.__rest(_a, ["environment"]);
                    return (Object.assign(Object.assign(Object.assign({}, config), debuggedTestConfig), { environment: mergeEnvironments(environment) }));
                };
                const mergeLldbConfigs = (config) => (Object.assign(Object.assign(Object.assign({}, config), debuggedTestConfig), { env: Object.assign(Object.assign(Object.assign({}, config.env), extraCtestEnvVars), env) }));
                disposables.push(vscode.debug.registerDebugConfigurationProvider('*', {
                    resolveDebugConfigurationWithSubstitutedVariables: (folder, config, token) => config.type === 'lldb'
                        ? mergeLldbConfigs(config)
                        : mergeConfigs(config),
                }));
                yield vscode.debug.startDebugging(this.workspaceFolder, debugConfig || defaultConfig);
            }
            catch (e) {
                this.log.error(`Error debugging CMake test ${id}: ${e}`);
            }
            finally {
                disposables.forEach((disposable) => disposable.dispose());
            }
        });
    }
    getDefaultDebugConfiguration() {
        return {
            name: 'CTest',
            type: 'cppdbg',
            request: 'launch',
            windows: {
                type: 'cppvsdbg',
            },
            linux: {
                type: 'cppdbg',
                MIMode: 'gdb',
            },
            osx: {
                type: 'cppdbg',
                MIMode: 'lldb',
            },
        };
    }
    getWorkspaceConfiguration() {
        return vscode.workspace.getConfiguration('cmakeExplorer', this.workspaceFolder.uri);
    }
    isCmakeWorkspace() {
        return tslib_1.__awaiter(this, void 0, void 0, function* () {
            const uris = yield vscode.workspace.findFiles('**/CMakeLists.txt', null, 1);
            return !!uris.length;
        });
    }
    getConfigStrings(names) {
        return tslib_1.__awaiter(this, void 0, void 0, function* () {
            const config = this.getWorkspaceConfiguration();
            const varMap = yield this.getVariableSubstitutionMap();
            return names.map((name) => this.configGetStr(config, varMap, name));
        });
    }
    configGetStr(config, varMap, key) {
        const configStr = config.get(key) || '';
        return substituteString(configStr, varMap);
    }
    getConfigObject(name) {
        return tslib_1.__awaiter(this, void 0, void 0, function* () {
            const config = this.getWorkspaceConfiguration();
            const varMap = yield this.getVariableSubstitutionMap();
            const obj = config.get(name) || {};
            for (let key in obj) {
                obj[key] = substituteString(obj[key], varMap);
            }
            return obj;
        });
    }
    getVariableSubstitutionMap() {
        return tslib_1.__awaiter(this, void 0, void 0, function* () {
            const substitutionMap = new Map([
                ['${workspaceFolder}', this.workspaceFolder.uri.fsPath],
            ]);
            for (const varname of ['buildType', 'buildDirectory']) {
                const command = `cmake.${varname}`;
                if ((yield vscode.commands.getCommands()).includes(command)) {
                    const value = (yield vscode.commands.executeCommand(command, this.workspaceFolder));
                    substitutionMap.set(`\${${varname}}`, value);
                }
                else {
                    substitutionMap.set(`\${${varname}}`, '');
                }
            }
            for (const [varname, value] of Object.entries(process.env)) {
                if (value !== undefined) {
                    substitutionMap.set(`\${env:${process.platform == 'win32' ? varname.toUpperCase() : varname}}`, value);
                }
            }
            return substitutionMap;
        });
    }
    getParallelJobs() {
        const config = vscode.workspace.getConfiguration('cmakeExplorer', this.workspaceFolder.uri);
        let parallelJobs = config.get('parallelJobs');
        if (!parallelJobs) {
            const cmakeConfig = vscode.workspace.getConfiguration('cmake', this.workspaceFolder.uri);
            parallelJobs = cmakeConfig.get('ctest.parallelJobs');
            if (!parallelJobs) {
                parallelJobs = cmakeConfig.get('parallelJobs');
                if (!parallelJobs) {
                    parallelJobs = os.cpus().length;
                }
            }
        }
        if (parallelJobs < 1)
            parallelJobs = 1;
        return parallelJobs;
    }
}
exports.CmakeAdapter = CmakeAdapter;
const getTestFileInfo = (test, testFileVar, testLineVar) => {
    const env = cmake_runner_1.getCmakeTestEnvironmentVariables(test);
    if (!env)
        return {};
    return {
        file: getFileFromEnvironment(env, testFileVar),
        line: getLineFromEnvironment(env, testLineVar),
    };
};
const getFileFromEnvironment = (env, fileVar) => env[fileVar];
const getLineFromEnvironment = (env, varname) => {
    const value = env[varname];
    if (value)
        return Number.parseInt(value) - 1;
    return;
};
const substituteString = (str, varMap) => {
    varMap.forEach((value, key) => {
        while (str.indexOf(key) > -1) {
            str = str.replace(key, value);
        }
    });
    return str;
};
const getVariableKey = (varname, env) => process.platform === 'win32'
    ? Object.keys(env).find((key) => key.toUpperCase() == varname.toUpperCase()) || varname
    : varname;
const getVariableIndex = (varname, environment) => process.platform === 'win32'
    ? environment.findIndex(({ name }) => name.toUpperCase() == varname.toUpperCase())
    : environment.findIndex(({ name }) => name == varname);
const mergeVariablesIntoProcessEnv = (variables) => {
    const result = Object.assign({}, process.env);
    for (let name in variables) {
        delete result[getVariableKey(name, process.env)];
        result[name] = variables[name];
    }
    return result;
};
const mergeVariablesIntoDebugEnv = (environment, variables) => {
    const result = [...environment];
    for (let name in variables) {
        const variableIndex = getVariableIndex(name, environment);
        if (variableIndex == -1) {
            result.push({ name, value: variables[name] });
        }
        else {
            result[variableIndex] = { name, value: variables[name] };
        }
    }
    return result;
};
//# sourceMappingURL=cmake-adapter.js.map