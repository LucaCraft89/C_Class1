import datetime
import os
import time

today = datetime.datetime.today()
weekday = today.weekday()

if weekday == 3 or weekday == 4:  # Thursday or Friday
    folder_name = "Lezionee" + today.strftime('%Y.%m.%d')
    repo_path = "C:\\Users\\lucac\\CDv"  # Replace with the actual path to your GitHub repo

    os.chdir(repo_path)  # Change to the repository directory
    os.mkdir(folder_name)  # Create the new folder in the repo
    os.chdir(folder_name)  # Change to the new folder

    # Create a new file inside the folder
    file_name = "testfile.txt"
    file = open(file_name, "w")
    file.write("This is a test file created on " + today.strftime('%Y/%m/%d'))
    file.close()

    # Commit the new file to git
    os.system("git add .")  # Stage all changes for commit
    os.system(f"git commit -m 'Comm1'")  # Commit the changes
    os.system("git push")  # Push the changes to the remote repo

    # Wait for a while to ensure that the new changes get synced to the remote repo
    time.sleep(10)

    # Delete the test file
    os.remove(file_name)