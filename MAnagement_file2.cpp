#include <iostream>
#include <string>
#include <direct.h>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

// Function to display the main menu
void mainMenu() {
    cout << "\n========== Directory Management System ==========\n";
    cout << "[1] List Files\n";
    cout << "[2] Create Directory\n";
    cout << "[3] Change Directory\n";
    cout << "[4] Exit\n";
    cout << "Enter option: ";
}

// Function to list all files in the current directory
void listFiles() {
    cout << "\nFiles in current directory:\n";
    try {
        for (const auto& entry : fs::directory_iterator(fs::current_path())) {
            cout << "- " << entry.path().filename().string() << endl;
        }
    }
    catch (const fs::filesystem_error& e) {
        cout << "Error accessing directory: " << e.what() << endl;
    }
}

// Function to create a new directory
void createDirectory() {
    string dirName;
    cout << "\nEnter new directory name: ";
    getline(cin, dirName);
    try {
        if (_access(dirName.c_str(), 0) == 0) {
            cout << "Error: Directory \"" << dirName << "\" already exists!\n";
        }
        else if (fs::create_directory(dirName)) {
            cout << "Directory \"" << dirName << "\" created successfully.\n";
        }
        else {
            cout << "Error: Failed to create directory '" << dirName << "'!\n";
        }
    }
    catch (const fs::filesystem_error& e) {
        cout << "Filesystem error: " << e.what() << endl;
    }
}

// Function to display the change directory submenu
void changeDirectoryMenu() {
    cout << "\nChange Directory Menu\n";
    cout << "[1] Move to Parent Directory\n";
    cout << "[2] Move to Root Directory\n";
    cout << "[3] Enter Custom Path\n";
    cout << "Enter choice: ";
}

// Function to change the current working directory
void changeDirectory() {
    int choice;
    changeDirectoryMenu();
    while (!(cin >> choice)) {
        cout << "Invalid input. Enter a number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cin.ignore();

    try {
        if (choice == 1) {
            fs::path current = fs::current_path();
            fs::path parent = current.parent_path();
            if (parent != current) {
                fs::current_path(parent);
                cout << "Changed to parent directory: " << fs::current_path().string() << endl;
            }
            else {
                cout << "Error: Already at root or no parent directory exists!\n";
            }
        }
        else if (choice == 2) {
            fs::path root = fs::current_path().root_path();
            fs::current_path(root);
            cout << "Changed to root directory: " << fs::current_path().string() << endl;
        }
        else if (choice == 3) {
            string path;
            cout << "Enter new directory path: ";
            getline(cin, path);
            if (_chdir(path.c_str()) == 0) {
                cout << "Changed to directory: " << fs::current_path().string() << endl;
            }
            else {
                cout << "Error: Directory \"" << path << "\" not found!\n";
            }
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
    catch (const fs::filesystem_error& e) {
        cout << "Filesystem error: " << e.what() << endl;
    }
}

// Function to handle the main menu
void mainMenuLoop() {
    int option;
    do {
        mainMenu();
        while (!(cin >> option)) {
            cout << "Invalid input. Enter a number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore();

        switch (option) {
        case 1:
            listFiles();
            break;
        case 2:
            createDirectory();
            break;
        case 3:
            changeDirectory();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (option != 4);
}

int main() {
    mainMenuLoop();
    return 0;
}
