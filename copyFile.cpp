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

bool copyFileContent(const string& sourceFile, const string& targetFile) {
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
        cout << "Error: Failed to copy file content" << endl;
        source.close();
        target.close();
        return false;
    }

    source.close();
    target.close();

    cout << "File content copied successfully" << endl;
    return true;
}

int main() {
    printHeader("File Copy Program");

    char startChoice;
    cout << "\nDo you want to copy a file? (Y/N): ";
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

    if (copyFileContent(sourceFile, targetFile)) {
        cout << "File content copied successfully to " << targetFile << endl;
    } else {
        cout << "File content copy failed" << endl;
    }
    return 0;
}
