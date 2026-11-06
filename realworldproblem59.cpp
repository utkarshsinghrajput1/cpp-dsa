// 59. Delivery Route Code
// Problem
// Route number qualify karega agar:
// - Digit sum = proper divisor count
// - Reverse > original
// - Number even ho
#include <iostream>
using namespace std;

int main() {
    int route;
    cin >> route;

    int temp = route;
    int digitSum = 0;
    int reverse = 0;

    while (temp > 0) {
        int digit = temp % 10;

        digitSum = digitSum + digit;
        reverse = reverse * 10 + digit;

        temp = temp / 10;
    }

    int properCount = 0;

    for (int d = 1; d < route; d++) {
        if (route % d == 0)
            properCount++;
    }

    if (digitSum == properCount) {
        if (reverse > route) {
            if (route % 2 == 0)
                cout << "VALID ROUTE";
            else
                cout << "INVALID ROUTE";
        } else {
            cout << "INVALID ROUTE";
        }
    } else {
        cout << "INVALID ROUTE";
    }

    return 0;
}