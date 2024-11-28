#include <iostream>
#include <sstream> 
#include <string>  
#include <iomanip> 

using namespace std;

int main() {
    string input; 
    double num1, num2, result; 
    char operation;
    char continueChoice;

    do {
        cout << "Enter a mathematical expression (e.g., 8 / 9): ";
        getline(cin, input); 

       
        stringstream ss(input);
        ss >> num1 >> operation >> num2;

       
        switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            }
            else {
                cout << "Error: Division by zero is not allowed.\n";
                continue; 
            }
            break;
        default:
            cout << "Invalid operation. Please use +, -, *, or /.\n";
            continue;

        // Display the result
        cout << fixed << setprecision(2); 
        cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << endl;

        // Ask if the user wants to continue
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> continueChoice;
        cin.ignore(); 

    } while (continueChoice == 'y' || continueChoice == 'Y'); 

    cout << "Thank you for using the calculator. Goodbye!\n";
    return 0;
}
