// 54. Water Tank Sensor
// Problem
// Har sensor reading ke liye:
// - Proper divisor sum find karo
// - Digit product find karo
// Sensor alert karega agar:

// proper divisor sum > digit product

// Aur digit sum odd ho.

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int alerts = 0;

    for (int i = 1; i <= N; i++) {
        int reading;
        cin >> reading;

        int properSum = 0;

        for (int d = 1; d < reading; d++) {
            if (reading % d == 0)
                properSum = properSum + d;
        }

        int temp = reading;
        int product = 1;
        int sum = 0;

        while (temp > 0) {
            int digit = temp % 10;

            product = product * digit;
            sum = sum + digit;

            temp = temp / 10;
        }

        if (properSum > product) {
            if (sum % 2 != 0)
                alerts++;
        }
    }

    cout << "Alerts: " << alerts;

    return 0;
}