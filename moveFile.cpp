#include <iostream>
#include <fstream>
#include <string>
#include <filesystem> // for checking file existence and directory creation
using namespace std;
namespace fs = std::filesystem;

void printHeader(const string& headerText) {
    int length = headerText.length();
    cout << "\t\t\t\t<"<<string(length + 8, '=')<<">"<<endl;
    cout << "\t\t\t\t"<< "=   " << headerText << "   =" << endl;
    cout << "\t\t\t\t<"<<string(length + 8, '=')<<">";
}

bool transferFile(const string& sourceFolder, const string& targetFolder, const string& fileName) {
    // Check if source file exists
    if (!fs::exists(sourceFolder + "/" + fileName)) {
        cout << "Error: Source file does not exist: " << fileName << endl;
        return false;
    }

    // Check if target folder exists, create if not
    if (!fs::exists(targetFolder)) {
        cout << "Target folder does not exist. Creating..." << endl;
        if (!fs::create_directory(targetFolder)) {
            cout << "Error: Failed to create target folder: " << targetFolder << endl;
            return false;
        }
    }

    // Check if target file exists
    if (fs::exists(targetFolder + "/" + fileName)) {
        char overwriteChoice;
        cout << "Target file already exists. Do you want to overwrite it? (Y/N): ";
        cin >> overwriteChoice;
        if (overwriteChoice != 'Y' && overwriteChoice != 'y') {
            cout << "File transfer aborted" << endl;
            return false;
        }
    }

    ifstream sourceFile(sourceFolder + "/" + fileName, ios::binary);
    if (!sourceFile) {
        cout << "Error: Failed to open source file " << fileName << endl;
        return false;
    }

    ofstream targetFile(targetFolder + "/" + fileName, ios::binary);
    if (!targetFile) {
        cout << "Error: Failed to open target file " << fileName << endl;
        return false;
    }

    targetFile << sourceFile.rdbuf();

    if (sourceFile.bad() || targetFile.bad()) {
        cout << "Error: Failed to transfer file " << fileName << endl;
        return false;
    }

    sourceFile.close();
    targetFile.close();

    // Delete the source file after successful transfer
    if (!fs::remove(sourceFolder + "/" + fileName)) {
        cout << "Error: Failed to delete source file " << fileName << endl;
        return false;
    }

    cout << "File transfer successful: " << fileName << endl;
    return true;
}
int main() {
    printHeader("Move File Program");

    string sourceFolder, targetFolder, fileName;
    
    char startChoice;
    cout << "\nDo you want to Move a file? (Y/N): ";
    cin >> startChoice;

    if (startChoice != 'Y' && startChoice != 'y') {
        cout << "Exiting the program.";
        return 0;
    }
    
    while (true) {
        cout << "\nEnter the Path of Source Folder: ";
        cin >> sourceFolder;

        cout << "Enter the Path of Target Folder: ";
        cin >> targetFolder;

        cout << "Enter the File Name: ";
        cin >> fileName;

        if (transferFile(sourceFolder, targetFolder, fileName)) {
            cout << "File transfer successful" << endl;
        } else {
            cout << "File transfer failed" << endl;
        }

        char choice;
        cout << "\nDo you want to transfer another file? (Y/N): ";
        cin >> choice;

        if (choice != 'Y' && choice != 'y') {
            break;
        }
    }

    return 0;
}
