#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

void printHeader(const string& headerText) {
    int length = headerText.length();
    cout << "\t\t\t\t<"<<string(length + 8, '=')<<">"<<endl;
    cout << "\t\t\t\t"<< "=   " << headerText << "   =" << endl;
    cout << "\t\t\t\t<"<<string(length + 8, '=')<<">";
}

int main() {
    srand(time(0));

    const int targetNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    printHeader("Number Guessing Game");

    cout << "\nI have selected a number between 1 and 100.\n";

    do {
        cout << "\nEnter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > targetNumber) {
            cout << "Too high! ";
            if (guess - targetNumber <= 10) {
                cout << "But you are close! Try again.\n";
            } else {
                cout << "Try again.\n";
            }
        }
        if (guess < targetNumber) {
            cout << "Too low! ";
            if (targetNumber - guess <= 10) {
                cout << "But you are close! Try again.\n";
            } else {
                cout << "Try again.\n";
            }
        }
        if (guess == targetNumber) {
            cout << "\nCongratulations! You guessed the number " << targetNumber << " in " << attempts << " attempts!\n";
            break;
        }
    } while (guess != targetNumber);

    sleep(2); // Sleep for 2 seconds
    cout << "\nThank you for playing!\n";

    return 0;
}
