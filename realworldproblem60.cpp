// 60. Server Load Inspector
// Problem
// N server loads diye jayenge.

// Server overloaded hoga agar:
// - Digit product > proper divisor sum
// - Odd digits ki count even ho
// - Number composite ho
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int overloaded = 0;

    for (int i = 1; i <= N; i++) {
        int load;
        cin >> load;

        int properSum = 0;

        for (int d = 1; d < load; d++) {
            if (load % d == 0)
                properSum = properSum + d;
        }

        int temp = load;
        int product = 1;
        int oddCount = 0;

        while (temp > 0) {
            int digit = temp % 10;

            product = product * digit;

            if (digit % 2 != 0)
                oddCount++;

            temp = temp / 10;
        }

        int divisors = 0;

        for (int d = 1; d <= load; d++) {
            if (load % d == 0)
                divisors++;
        }

        if (product > properSum) {
            if (oddCount % 2 == 0) {
                if (divisors > 2)
                    overloaded++;
            }
        }
    }

    cout << overloaded;

    return 0;
}