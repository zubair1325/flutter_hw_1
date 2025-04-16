#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <unistd.h>

using namespace std;

int main() {
    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Create a new file" << endl;
        cout << "2. Open an existing file for editing" << endl;
        cout << "3. Exit" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string fileName;
                cout << "Enter the file name: ";
                cin >> fileName;

                fstream file(fileName + ".txt", ios::out);
                if (!file) {
                    cout << "Error in creating file!!!" << endl;
                } else {
                    cout << "File created successfully." << endl;
                    file.close();
                }
                break;
            }
            case 2: {
                string fileName;
                string filePath = "/home/usmanifty/Desktop/"; // Change this to your desired directory

                cout << "Enter the file name: ";
                cin >> fileName;

                string command = "gnome-text-editor " + filePath + fileName + ".txt"; // Open the file in GNOME Text Editor
                system(command.c_str()); // Execute the command to open the file in GNOME Text Editor
                break;
            }
            case 3:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
        }
    }

    return 0;
}

// #include <iostream>
// #include <fstream>
// #include <string>
// #include <cstdlib>
// #include <unistd.h>

// using namespace std;

// void createNewFile() {
//     fstream file;
//     string fileName;
//     cout << "Enter the file name: ";
//     cin >> fileName;
//     file.open(fileName + ".txt", ios::out);
//     if (!file) {
//         cout << "Error in creating file!!!" << endl;
//     } else {
//         cout << "File created successfully." << endl;
//         file.close();
//     }
// }

// void editExistingFile() {
//     string fileName;
//     string filePath = "/home/usmanifty/Desktop/"; // Change this to your desired directory

//     cout << "Enter the file name: ";
//     cin >> fileName;

//     // Open the file for reading and writing
//     fstream file(filePath + fileName, ios::in | ios::out);

//     if (!file.is_open()) {
//         cout << "Error opening file!" << endl;
//         return;
//     }

//     // Read the contents of the file
//     string line;
//     cout << "File contents:" << endl;
//     int lineNumber = 1;
//     while (getline(file, line)) {
//         cout << lineNumber << ": " << line << endl;
//         lineNumber++;
//     }

//     // Move file cursor to the beginning for editing
//     file.clear();
//     file.seekp(0, ios::beg);

//     // Ask the user for input line number and text
//     cout << "Enter line number to edit (0 for new line): ";
//     int editLineNumber;
//     cin >> editLineNumber;

//     // Validate input line number
//     if (editLineNumber < 0) {
//         cout << "Invalid line number!" << endl;
//         return;
//     }

//     // Move file cursor to the specified line
//     if (editLineNumber > 0) {
//         file.seekp(0, ios::beg);
//         for (int i = 1; i < editLineNumber; i++) {
//             if (!getline(file, line)) {
//                 cout << "Line number not found!" << endl;
//                 return;
//             }
//         }
//     }

//     cin.ignore(); // Ignore the newline character left by cin

//     // Ask the user for input text
//     cout << "Enter text (Enter '#' to save and exit editing):" << endl;
//     string input;
//     while (getline(cin, input)) {
//         if (input == "#") break; // Exit loop if '#' is entered

//         if (editLineNumber == 0) {
//             file.seekp(0, ios::end); // Move cursor to end for new line
//         }

//         file << input << endl; // Write input to file
//     }

//     cout << "Text saved. Exiting..." << endl;

//     // Close the file
//     file.close();
// }

// int main() {
//     while (true) {
//         cout << "Choose an option:" << endl;
//         cout << "1. Create a new file" << endl;
//         cout << "2. Edit an existing file" << endl;
//         cout << "3. Exit" << endl;

//         int choice;
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 createNewFile();
//                 break;
//             case 2:
//                 editExistingFile();
//                 break;
//             case 3:
//                 cout << "Exiting program." << endl;
//                 return 0;
//             default:
//                 cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
//         }
//     }

//     return 0;
// }
