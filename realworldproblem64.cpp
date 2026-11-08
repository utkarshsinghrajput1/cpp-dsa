// 64. Movie Ticket Serial Checker
// Problem
// Serial number special hoga agar:
// - Serial ke har divisor ka digit sum calculate karo
// - Prime digit-sum wale divisors ki count odd ho
// - Original digit sum even ho
#include <iostream>
using namespace std;

int main() {
    int serial;
    cin >> serial;

    int temp = serial;
    int originalSum = 0;

    while (temp > 0) {
        originalSum = originalSum + temp % 10;
        temp = temp / 10;
    }

    int primeDigitDivisors = 0;

    for (int d = 1; d <= serial; d++) {

        if (serial % d == 0) {

            int x = d;
            int sum = 0;

            while (x > 0) {
                sum = sum + x % 10;
                x = x / 10;
            }

            int count = 0;

            for (int p = 1; p <= sum; p++) {
                if (sum % p == 0)
                    count++;
            }

            if (count == 2)
                primeDigitDivisors++;
        }
    }

    if (originalSum % 2 == 0) {
        if (primeDigitDivisors % 2 != 0)
            cout << "SPECIAL TICKET";
        else
            cout << "NORMAL TICKET";
    } else {
        cout << "NORMAL TICKET";
    }

    return 0;
}