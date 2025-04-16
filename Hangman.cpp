#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

void printHangman(int attempts) {
    switch(attempts) {
        case 1:
            cout << "  O" << endl;
            break;
        case 2:
            cout << "  O" << endl;
            cout << "  |" << endl;
            break;
        case 3:
            cout << "  O" << endl;
            cout << " \\|" << endl;
            break;
        case 4:
            cout << "  O" << endl;
            cout << " \\|/" << endl;
            break;
        case 5:
            cout << "  O" << endl;
            cout << " \\|/" << endl;
            cout << " /" << endl;
            break;
        case 6:
            cout << "  O" << endl;
            cout << " \\|/" << endl;
            cout << " / \\" << endl;
            break;
    }
}

int main() {
    string secretWord;
    string guessedWord;
    char incorrectLetters[6];

    int maxAttempts = 6;
    int attempts = 0;

    cout << "\t\t\tWelcome to Hangman!" << endl;
    cout << "You have to guess the secret word." << endl;
    cout << "Enter the secret word: ";
    cin >> secretWord;

    guessedWord = string(secretWord.length(), '_');

    while (true) {
        cout << "\nGuessed word: " << guessedWord << endl;
        printHangman(attempts);
        cout << "Incorrect letters: ";
        for (int i = 0; i < attempts; i++) {
            cout << incorrectLetters[i] << " ";
        }
        cout << endl;
        cout << "Attempts left: " << maxAttempts - attempts << endl;

        cout << "\nGuess a letter: ";
        char guess;
        cin >> guess;
        bool correctGuess = false;
        for (int i = 0; i < secretWord.length(); i++) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }
        if (!correctGuess) {
            incorrectLetters[attempts] = guess;
            attempts++;
        }

        if (guessedWord == secretWord) {
            cout << "Congratulations! You guessed the word." << endl;
            break;
        }

        if (attempts == maxAttempts) {
            cout << "You lost! The word was: " << secretWord << endl;
            break;
        }
    }
    sleep(4);
    return 0;
}
