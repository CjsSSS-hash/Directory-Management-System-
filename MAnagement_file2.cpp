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
    cout << "[3] Exit\n";
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
        if (fs::create_directory(dirName)) {
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
        cin.ignore(); // Clear input buffer

        switch (option) {
        case 1:
            listFiles();
            break;
        case 2:
            createDirectory();
            break;
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (option != 3);
}

int main() {
    mainMenuLoop();
    return 0;
}
