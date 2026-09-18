// Problem: Take an integer input from the user and reverse it (e.g., 1234 becomes 4321).
// Solution: Below is a C++ program that takes an integer input from the user and reverses it.

#include <iostream>
using namespace std;

int main() {
    int num, remainder;
    int reversedNum = 0;
    
    cout << "Enter an integer: ";
    cin >> num;
    
    while (num != 0) {
        remainder = num % 10;                // Get the last digit
        reversedNum = reversedNum * 10 + remainder; // Append digit to reversed number
        num /= 10;                           // Remove the last digit
    }
    
    cout << "Reversed Number: " << reversedNum << endl;
    return 0;
}
