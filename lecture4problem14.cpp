// Q. Simple Calculator
// Do numbers aur operator input lo
// +
// -
// *
// /
#include <iostream>
using namespace std;

int main() {
    float a, b;
    char op;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> b;

    if (op == '+') {
        cout << "Result = " << a + b;
    }
    else if (op == '-') {
        cout << "Result = " << a - b;
    }
    else if (op == '*') {
        cout << "Result = " << a * b;
    }
    else if (op == '/') {
        if (b != 0) {
            cout << "Result = " << a / b;
        }
        else {
            cout << "Cannot divide by zero";
        }
    }
    else {
        cout << "Invalid operator";
    }

    return 0;
}