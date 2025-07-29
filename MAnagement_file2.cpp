#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void mainMenu() { /* Unchanged */ }

void listFilesMenu() {
    cout << "\nList Files Menu\n";
    cout << "[1] List All Files\n";
    cout << "Enter your choice: ";
}

void listFiles() {
    int choice;
    listFilesMenu();
    cin >> choice;
    cin.ignore();
    HANDLE hFind;
    WIN32_FIND_DATA findData;
    if (choice == 1) {
        cout << "\nListing all files in current directory:\n";
        hFind = FindFirstFile("*.*", &findData);
        if (hFind != INVALID_HANDLE_VALUE) {
            do {
                cout << findData.cFileName << endl;
            } while (FindNextFile(hFind, &findData));
            FindClose(hFind);
        } else {
            cout << "Error: Unable to list files!\n";
        }
    } else {
        cout << "Invalid choice!\n";
    }
}

int main() {
    int choice;
    mainMenu();
    cin >> choice;
    cin.ignore();
    if (choice == 1) listFiles();
    else if (choice == 4) cout << "Exiting program.\n";
    else cout << "Invalid choice!\n";
    return 0;
}
