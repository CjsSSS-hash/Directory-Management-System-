#include <iostream>
#include <filesystem>
#include <string>
#include <direct.h>

using namespace std;
namespace fs = std::filesystem;

// Function to display the main menu and get user choice
void mainMenu() {
    cout << "\nDirectory Management System\n";
    cout << "[1] List Files\n";
    cout << "[2] Create Directory\n";
    cout << "[3] Change Directory\n";
    cout << "[4] Exit\n";
    cout << "Enter your choice: ";
}

// Function to display the list files submenu and get user choice
void listFilesMenu() {
    cout << "\nList Files Menu\n";
    cout << "[1] List All Files\n";
    cout << "[2] List Files by Extension\n";
    cout << "[3] List Files by Pattern\n";
    cout << "Enter your choice: ";
}
