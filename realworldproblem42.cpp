// 42. Electricity Meter Analyzer
// Problem
// L se R tak meter numbers check karo.

// Meter suspicious hoga agar:
// - Digit sum > total divisor count
// - Number composite ho
// - Proper divisors ka sum odd ho
#include <iostream>
using namespace std;

int main() {
    int L, R;
    cin >> L >> R;

    int suspicious = 0;

    for (int n = L; n <= R; n++) {

        int digitSum = 0;
        int temp = n;

        while (temp > 0) {
            digitSum = digitSum + temp % 10;
            temp = temp / 10;
        }

        int divisorCount = 0;
        int properSum = 0;

        for (int d = 1; d <= n; d++) {
            if (n % d == 0) {
                divisorCount++;

                if (d < n)
                    properSum = properSum + d;
            }
        }

        if (divisorCount > 2) {
            if (digitSum > divisorCount) {
                if (properSum % 2 != 0)
                    suspicious++;
            }
        }
    }

    cout << suspicious;

    return 0;
}