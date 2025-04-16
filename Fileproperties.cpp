#include <iostream>
#include <sys/stat.h>
#include <unistd.h>


using namespace std;

void printHeader(const string& headerText) {
    int length = headerText.length();
    cout << "\t\t\t\t<"<<string(length + 8, '=')<<">"<<endl;
    cout << "\t\t\t\t"<< "=   " << headerText << "   =" << endl;
    cout << "\t\t\t\t<"<<string(length + 8, '=')<<">";
}

int main()
{
    printHeader("File Information Program");

    string filename;
    while(true)
    {
        cout << "\nEnter File name (or 'exit' to quit): ";
        cin >> filename;

        if (filename == "exit" || filename == "Exit" || filename == "EXIT") {
            cout << "Exiting the program." << endl;
            break;
        }

        struct stat fileStat;

        if (stat(filename.c_str(), &fileStat) < 0) {
            cout << "Failed to get file properties" << endl;
            continue;
        }

        cout << "\nFile name: " << filename << endl;
        cout << "Size: " << fileStat.st_size << " bytes" << endl;
        cout << "Owner ID: " << fileStat.st_uid << endl;
        cout << "Group ID: " << fileStat.st_gid << endl;
        cout << "Permissions: " << fileStat.st_mode << endl;
        cout << "Last access time: " << ctime(&fileStat.st_atime);
        cout << "Last modification time: " << ctime(&fileStat.st_mtime);
        cout << "Last status change time: " << ctime(&fileStat.st_ctime);

        char choice;
        cout << "\nDo you want to check another file? (Y/N): ";
        cin >> choice;
        if (choice != 'Y' && choice != 'y') {
            cout << "Exiting the program." << endl;
            break;
        }
    }

    return 0;
}
