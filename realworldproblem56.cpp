// 56. Smart Traffic Signal Analyzer
// Problem
// Vehicle numbers [L, R] mein check karo.

// Signal priority milegi agar:
// - Number 9 se divisible ho
// - Digit sum odd ho
// - Reverse bhi 3 se divisible ho
// - Number composite ho

#include <iostream>
using namespace std;

int main() {
    int L, R;
    cin >> L >> R;

    for (int n = L; n <= R; n++) {

        int temp = n;
        int sum = 0;
        int reverse = 0;

        while (temp > 0) {
            int digit = temp % 10;

            sum = sum + digit;
            reverse = reverse * 10 + digit;

            temp = temp / 10;
        }

        int divisors = 0;

        for (int d = 1; d <= n; d++) {
            if (n % d == 0)
                divisors++;
        }

        if (n % 9 == 0) {
            if (sum % 2 != 0) {
                if (reverse % 3 == 0) {
                    if (divisors > 2)
                        cout << n << " ";
                }
            }
        }
    }

    return 0;
}