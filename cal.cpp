#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char operation;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the operator (+, -, *, /): ";
    cin >> operation;

    cout << "Enter the second number: ";
    cin >> num2;

    double result;
    bool isValidOperation = true;

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
            if (num2 != 0)
                result = num1 / num2;
            else {
                cout << "Error: Division by zero is not allowed." << endl;
                isValidOperation = false;
            }
            break;
        default:
            cout << "Error: Invalid operator." << endl;
            isValidOperation = false;
    }

    if (isValidOperation)
        cout << "Result: " << result << endl;

    return 0;
}
