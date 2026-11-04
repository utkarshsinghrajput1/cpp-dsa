// 51. Mobile Battery Cycle Monitor
// Problem
// Battery health number repeatedly change hoga K rounds tak.

// Har round:
// - Digit sum S
// - Even digit count E
// Rules:
// - S even → N = N + E
// - S odd → N = N - E
// - N <= 0 → FAILED
// - N prime → HEALTHY
#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int round = 1;
    int stop = 0;

    while (round <= K && stop == 0) {

        int temp = N;
        int sum = 0;
        int evenCount = 0;

        while (temp > 0) {
            int digit = temp % 10;

            sum = sum + digit;

            if (digit % 2 == 0)
                evenCount++;

            temp = temp / 10;
        }

        if (sum % 2 == 0)
            N = N + evenCount;
        else
            N = N - evenCount;

        if (N <= 0) {
            cout << "FAILED";
            stop = 1;
        } else {
            int divisors = 0;

            for (int d = 1; d <= N; d++) {
                if (N % d == 0)
                    divisors++;
            }

            if (divisors == 2) {
                cout << "HEALTHY";
                stop = 1;
            }
        }

        round++;
    }

    if (stop == 0)
        cout << "FINAL: " << N;

    return 0;
}