// 65. Factory Machine Cycle
// Problem
// Machine number ke har round mein:
// - Proper divisor sum S
// - Largest digit L
// Rules:
// - S even → N = N + L
// - S odd → N = N - L
// Agar prime mile → MACHINE STABLE.
#include <iostream> 
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int round = 1;
    int stop = 0;

    while (round <= K && stop == 0) {

        int S = 0;

        for (int d = 1; d < N; d++) {
            if (N % d == 0)
                S = S + d;
        }

        int temp = N;
        int largest = 0;

        while (temp > 0) {
            int digit = temp % 10;

            if (digit > largest)
                largest = digit;

            temp = temp / 10;
        }

        if (S % 2 == 0)
            N = N + largest;
        else
            N = N - largest;

        if (N <= 0) {
            cout << "MACHINE FAILED";
            stop = 1;
        } else {
            int divisors = 0;

            for (int d = 1; d <= N; d++) {
                if (N % d == 0)
                    divisors++;
            }

            if (divisors == 2) {
                cout << "MACHINE STABLE";
                stop = 1;
            }
        }

        round++;
    }

    if (stop == 0)
        cout << "FINAL CYCLE: " << N;

    return 0;
}