// Q. Triangle Valid Hai Ya Nahi?
// Three sides input lo.
// Triangle tabhi possible hai jab:
// a + b > c
// a + c > b
// b + c > a
#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    cout << "Enter three sides: ";
    cin >> a >> b >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "Invalid sides";
    }
    else if (a + b > c &&
             a + c > b &&
             b + c > a) {

        cout << "Valid Triangle";
    }
    else {
        cout << "Invalid Triangle";
    }

    return 0;
}