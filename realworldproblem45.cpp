// 45. Hospital Patient Token System
// Problem
// Patient token special hoga agar:
// - Token ke digits ka product even ho
// - Total divisors > digit count
// - Number composite ho
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int special = 0;

    for (int i = 1; i <= N; i++) {
        int token;
        cin >> token;

        int temp = token;
        int product = 1;
        int digitCount = 0;

        while (temp > 0) {
            int digit = temp % 10;

            product = product * digit;
            digitCount++;

            temp = temp / 10;
        }

        int divisors = 0;

        for (int d = 1; d <= token; d++) {
            if (token % d == 0)
                divisors++;
        }

        if (product % 2 == 0) {
            if (divisors > digitCount) {
                if (divisors > 2)
                    special++;
            }
        }
    }

    cout << "Special Tokens: " << special;

    return 0;
}