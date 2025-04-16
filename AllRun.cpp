#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    string objName[14];
    string filepath;
    
    objName[0] = "calculator";
    objName[1] = "clock";
    objName[2] = "copyFile";
    objName[3] = "deleteFile";
    objName[4] = "Fileproperties";
    objName[5] = "moveFile";
    objName[6] = "notepad";
    objName[7] = "song";
    objName[8] = "video";
    objName[9] = "RockPaperScissors";
    objName[10] = "numberGuess";
    objName[11] = "Hangman";
     objName[12] = "intro";
    objName[13] = "main";
    
    // Compiling all programs
    for (int i = 0; i < 13; i++) {
        filepath = "/home/zubair1325/Documents/p2/" + objName[i] + ".cpp";
        string command = "g++ -o " + objName[i] + " " + filepath;
        int result = system(command.c_str());
        cout << objName[i] << " is compiling..." << endl;
        if (result == 0) {
            cout << "Command for " << objName[i] << " executed successfully." << endl;
        } else {
            cerr << "Error executing command for " << objName[i] << endl;
        }
    }

    // Compiling Main using thread library
    filepath = "/home/zubair1325/Documents/p2/" + objName[13] + ".cpp";
    string command = "g++ -pthread -o " + objName[13] + " " + filepath;
    int result = system(command.c_str());
    cout << objName[13] << " is compiling..." << endl;
    if (result == 0) {
        cout << "Command for " << objName[13] << " executed successfully." << endl;
    } else {
        cerr << "Error executing command for " << objName[13] << endl;
    }

    return 0;
}




