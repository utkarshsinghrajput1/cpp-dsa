// 66. City House Number Investigation
// Problem
// House number suspicious hai agar:
// - Reverse aur original ka difference even ho
// - Digit sum > proper divisor count
// - Number composite ho
#include <iostream>
using namespace std;

int main() {
    int house;
    cin >> house;

    int temp = house;
    int reverse = 0;
    int digitSum = 0;

    while (temp > 0) {
        int digit = temp % 10;

        reverse = reverse * 10 + digit;
        digitSum = digitSum + digit;

        temp = temp / 10;
    }

    int difference = house - reverse;

    if (difference < 0)
        difference = -difference;

    int properCount = 0;
    int divisors = 0;

    for (int d = 1; d <= house; d++) {
        if (house % d == 0) {
            divisors++;

            if (d < house)
                properCount++;
        }
    }

    if (difference % 2 == 0) {
        if (digitSum > properCount) {
            if (divisors > 2)
                cout << "SUSPICIOUS HOUSE";
            else
                cout << "NORMAL HOUSE";
        } else {
            cout << "NORMAL HOUSE";
        }
    } else {
        cout << "NORMAL HOUSE";
    }

    return 0;
}