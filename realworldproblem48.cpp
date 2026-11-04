// 8. Railway Platform Number Test
// Problem
// Platform number qualify karega agar:
// - Reverse number original se bada ho
// - Digit sum divisible by 3 ho
// - Number composite ho
#include <iostream>
using namespace std;

int main() {
    int L, R;
    cin >> L >> R;

    int total = 0;

    for (int n = L; n <= R; n++) {
        int temp = n;
        int reverse = 0;
        int sum = 0;

        while (temp > 0) {
            int digit = temp % 10;

            reverse = reverse * 10 + digit;
            sum = sum + digit;

            temp = temp / 10;
        }

        int divisors = 0;

        for (int d = 1; d <= n; d++) {
            if (n % d == 0)
                divisors++;
        }

        if (reverse > n) {
            if (sum % 3 == 0) {
                if (divisors > 2)
                    total++;
            }
        }
    }

    cout << total;

    return 0;
}