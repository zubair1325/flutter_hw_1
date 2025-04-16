#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <unistd.h>

using namespace std;

int main() {
    double num1, num2, result;
    char op;
    while (true) {
        // Display the menu options
        cout << "Calculator Menu:" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "5. Exponentiation (^)" << endl;
        cout << "6. Modulus (%)" << endl;
        cout << "Enter(Q/q) To Quit" << endl;
        cout << "Enter your choice In Number: ";

        cin >> op;

        if (op == 'q' || op == 'Q') {
            cout << "Exiting the calculator. Goodbye!" << endl;
            break;
        }

        if (op >= '1' && op <= '6') {
            cout << "Enter the first number: ";
            cin >> num1;
            cout << "Enter the second number: ";
            cin >> num2;

            // Perform the requested operation
            switch (op) {
                case '1':
                    result = num1 + num2;
                    cout << "Result: " << result << endl;
                    break;
                case '2':
                    result = num1 - num2;
                    cout << "Result: " << result << endl;
                    break;
                case '3':
                    result = num1 * num2;
                    cout << "Result: " << result << endl;
                    break;
                case '4':
                    if (num2 != 0) {
                        result = num1 / num2;
                        cout << "Result: " << result << endl;
                    } else {
                        cerr << "Error: Division by zero." << endl;
                    }
                    break;
                case '5':
                    result = pow(num1, num2);
                    cout << "Result: " << result << endl;
                    break;
                case '6':
                    if (num2 != 0) {
                        result = fmod(num1, num2);
                        cout << "Result: " << result << endl;
                    } else {
                        cerr << "Error: Modulus by zero." << endl;
                    }
                    break;
            }
        } else {
            cerr << "Invalid input. Please enter a valid option." << endl;
        }

        // Clear input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}
