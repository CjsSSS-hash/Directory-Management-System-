#include <iostream>
#include <string>
using namespace std;

void mainMenu() {
    cout << "\nDirectory Management System\n";
    cout << "[1] List Files\n";
    cout << "[2] Create Directory\n";
    cout << "[3] Change Directory\n";
    cout << "[4] Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    mainMenu();
    return 0;
}
