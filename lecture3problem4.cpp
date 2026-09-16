/* Write a C++ program that asks the user to enter an integer number. Use an if-else statement to check if the number is even or odd, and print the result.
Here is a C++ program that checks if a number entered by the user is even or odd using an if-else statement */


#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    if (num % 2 == 0) {
        cout << "The number is even." << endl;
    } else {
        cout << "The number is odd." << endl;
    }

    return 0;
}
