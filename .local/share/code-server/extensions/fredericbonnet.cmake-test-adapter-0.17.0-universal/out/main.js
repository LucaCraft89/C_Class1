"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.deactivate = exports.activate = void 0;
const tslib_1 = require("tslib");
const vscode = require("vscode");
const vscode_test_adapter_api_1 = require("vscode-test-adapter-api");
const vscode_test_adapter_util_1 = require("vscode-test-adapter-util");
const cmake_adapter_1 = require("./cmake-adapter");
function activate(context) {
    return tslib_1.__awaiter(this, void 0, void 0, function* () {
        const workspaceFolder = (vscode.workspace.workspaceFolders || [])[0];
        const log = new vscode_test_adapter_util_1.Log('cmakeExplorer', workspaceFolder, 'CMake Explorer Log');
        context.subscriptions.push(log);
        const config = vscode.workspace.getConfiguration('cmakeExplorer', workspaceFolder.uri);
        const cmakeIntegration = config.get('cmakeIntegration');
        if (cmakeIntegration === 'true' || cmakeIntegration === true) {
            let cmakeExtension = vscode.extensions.getExtension('ms-vscode.cmake-tools');
            if (!cmakeExtension) {
                const message = `CMake integration is enabled but the CMake Tools extension is not installed`;
                log.warn(message);
            }
            else if (!cmakeExtension.isActive) {
                log.warn(`CMake integration is enabled but the CMake Tools extension is not active`);
                yield cmakeExtension.activate();
            }
        }
        const testExplorerExtension = vscode.extensions.getExtension(vscode_test_adapter_api_1.testExplorerExtensionId);
        if (log.enabled)
            log.info(`Test Explorer ${testExplorerExtension ? '' : 'not '}found`);
        if (testExplorerExtension) {
            const testHub = testExplorerExtension.exports;
            context.subscriptions.push(new vscode_test_adapter_util_1.TestAdapterRegistrar(testHub, (workspaceFolder) => new cmake_adapter_1.CmakeAdapter(workspaceFolder, log), log));
        }
    });
}
exports.activate = activate;
function deactivate() { }
exports.deactivate = deactivate;
//# sourceMappingURL=main.js.map