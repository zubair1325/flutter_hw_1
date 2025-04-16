#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void printHeader(const string& headerText) {
    int length = headerText.length();
    cout << "\t\t\t\t<"<<string(length + 8, '=')<<">"<<endl;
    cout << "\t\t\t\t"<< "=   " << headerText << "   =" << endl;
    cout << "\t\t\t\t<"<<string(length + 8, '=')<<">";
}

bool cutFileContent(const string& sourceFile, const string& targetFile) {
    ifstream source(sourceFile);
    if (!source) {
        cout << "Error: Failed to open source file " << sourceFile << endl;
        return false;
    }

    ofstream target(targetFile);
    if (!target) {
        cout << "Error: Failed to open target file " << targetFile << endl;
        source.close();
        return false;
    }

    target << source.rdbuf();

    if (source.bad() || target.bad()) {
        cout << "Error: Failed to cut file content" << endl;
        source.close();
        target.close();
        return false;
    }

    source.close();
    target.close();

    if (remove(sourceFile.c_str()) != 0) {
        cout << "Error: Failed to delete source file " << sourceFile << endl;
        return false;
    }

    cout << "File content cut successful" << endl;
    return true;
}

int main() {
    printHeader("File Content Cut Program");

    char startChoice;
    cout << "\nDo you want to cut a file? (Y/N): ";
    cin >> startChoice;

    if (startChoice != 'Y' && startChoice != 'y') {
        cout << "Exiting the program." << endl;
        return 0;
    }

    string sourceFile, targetFile;

    cout << "\nEnter the Path of Source File: ";
    cin >> sourceFile;

    cout << "Enter the Path of Target File: ";
    cin >> targetFile;

    if (cutFileContent(sourceFile, targetFile)) {
        cout << "File content cut successful" << endl;

        char choice;
        cout << "\nDo you want to perform another operation?\n"
                "1. Cut another file\n"
                "2. Exit program\n"
                "Enter your choice (1/2): ";
        cin >> choice;

        switch (choice) {
            case '1':
                // Perform another file cut operation
                main();
                break;
            case '2':
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Exiting the program." << endl;
                return 0;
        }
    } else {
        cout << "File content cut failed" << endl;
    }

    return 0;
}
