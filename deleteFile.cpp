#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void printHeader(const string& headerText) {
    int length = headerText.length();
    cout << "\t\t\t\t<"<<string(length + 8, '=')<<">"<<endl;
    cout << "\t\t\t\t"<< "=   " << headerText << "   =" << endl;
    cout << "\t\t\t\t<"<<string(length + 8, '=')<<">";
}

int main() {
    printHeader("File Deletion Program");

    int status;
    char fileName[20];

 char startChoice;
    cout << "\nDo you want to Delete a file? (Y/N): ";
    cin >> startChoice;

    if (startChoice != 'Y' && startChoice != 'y') {
        cout << "Exiting the program.";
        return 0;
    }

    while (true) {
        cout << "\nEnter the Name of File: ";
        cin >> fileName;

        status = remove(fileName);
        if (status == 0)
            cout << "\nFile Deleted Successfully!" << endl;
        else
            cout << "\nError Occurred!" << endl;
        cout << endl;

        char choice;
        cout << "Do you want to delete another file? (Y/N): ";
        cin >> choice;

        if (choice != 'Y' && choice != 'y')
            break;
    }

    return 0;
}
