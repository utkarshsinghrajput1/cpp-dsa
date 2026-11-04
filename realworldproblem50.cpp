// 10. School Ranking Analyzer
// Problem
// Student marks L se R ke beech hain.

// Special marks:
// - Digit sum > reverse ke digit sum nahi — instead reverse > original
// - Even digits ki count = odd digits ki count
// - Total divisors even hon
#include <iostream>
using namespace std;

int main() {
    int L, R;
    cin >> L >> R;

    for (int n = L; n <= R; n++) {

        int temp = n;
        int reverse = 0;
        int evenCount = 0;
        int oddCount = 0;

        while (temp > 0) {
            int digit = temp % 10;

            reverse = reverse * 10 + digit;

            if (digit % 2 == 0)
                evenCount++;
            else
                oddCount++;

            temp = temp / 10;
        }

        int divisors = 0;

        for (int d = 1; d <= n; d++) {
            if (n % d == 0)
                divisors++;
        }

        if (reverse > n) {
            if (evenCount == oddCount) {
                if (divisors % 2 == 0)
                    cout << n << " ";
            }
        }
    }

    return 0;
}