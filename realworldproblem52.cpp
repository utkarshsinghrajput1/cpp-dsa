// 52. Bank Fraud Score Detector
// Problem
// Transaction ID suspicious hai agar:
// - Digit sum divisible by number of digits
// - Reverse < original
// - Proper divisor sum even ho
#include <iostream>
using namespace std;

int main() {
    int id;
    cin >> id;

    int temp = id;
    int sum = 0;
    int count = 0;
    int reverse = 0;

    while (temp > 0) {
        int digit = temp % 10;

        sum = sum + digit;
        count++;
        reverse = reverse * 10 + digit;

        temp = temp / 10;
    }

    int properSum = 0;

    for (int d = 1; d < id; d++) {
        if (id % d == 0)
            properSum = properSum + d;
    }

    if (count > 0 && sum % count == 0) {
        if (reverse < id) {
            if (properSum % 2 == 0)
                cout << "SUSPICIOUS";
            else
                cout << "SAFE";
        } else {
            cout << "SAFE";
        }
    } else {
        cout << "SAFE";
    }

    return 0;
}