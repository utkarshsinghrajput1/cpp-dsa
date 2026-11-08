// 62. Smart Farming Crop Code
// Problem
// Crop code special hoga agar:
// - Proper divisor sum divisible by digit sum
// - Exactly one odd digit ho
// - Number palindrome na ho
#include <iostream>
using namespace std;

int main() {
    int code;
    cin >> code;

    int temp = code;
    int digitSum = 0;
    int oddCount = 0;
    int reverse = 0;

    while (temp > 0) {
        int digit = temp % 10;

        digitSum = digitSum + digit;

        if (digit % 2 != 0)
            oddCount++;

        reverse = reverse * 10 + digit;

        temp = temp / 10;
    }

    int properSum = 0;

    for (int d = 1; d < code; d++) {
        if (code % d == 0)
            properSum = properSum + d;
    }

    if (digitSum > 0) {
        if (properSum % digitSum == 0) {
            if (oddCount == 1) {
                if (reverse != code)
                    cout << "SPECIAL CROP";
                else
                    cout << "NORMAL";
            } else {
                cout << "NORMAL";
            }
        } else {
            cout << "NORMAL";
        }
    } else {
        cout << "NORMAL";
    }

    return 0;
}