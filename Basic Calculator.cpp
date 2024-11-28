#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    double num1, num2, result;
    char operation;
    char continueChoice;

    do {
        cout << "Enter a mathematical expression (e.g., 8 / 9): ";
        cin >> num1 >> operation >> num2;

        if (operation == '+') {
            result = num1 + num2;
        } else if (operation == '-') {
            result = num1 - num2;
        } else if (operation == '*') {
            result = num1 * num2;
        } else if (operation == '/') {
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Error: Division by zero is not allowed.\n";
                continue;
            }
        } else {
            cout << "Invalid operation. Please use +, -, *, or /.\n";
            continue;
        }

        cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << endl;

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> continueChoice;

    } while (continueChoice == 'y' || continueChoice == 'Y');

    cout << "Thank you for using the calculator. Goodbye!\n";
    return 0;
}
