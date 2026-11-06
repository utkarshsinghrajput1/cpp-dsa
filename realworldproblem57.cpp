// 57. Robot Energy Survival
// Problem
// Robot energy N hai aur K rounds hain.

// Har round:
// - Proper divisor sum = S
// - Digit sum = D
// Rules:
// - S > N → N = S - D
// - S <= N → N = N - D
// Agar N prime → ROBOT SAVED
// Agar N <= 0 → ROBOT SHUTDOWN
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
        int D = 0;

        while (temp > 0) {
            D = D + temp % 10;
            temp = temp / 10;
        }

        if (S > N)
            N = S - D;
        else
            N = N - D;

        if (N <= 0) {
            cout << "ROBOT SHUTDOWN";
            stop = 1;
        } else {
            int divisors = 0;

            for (int d = 1; d <= N; d++) {
                if (N % d == 0)
                    divisors++;
            }

            if (divisors == 2) {
                cout << "ROBOT SAVED";
                stop = 1;
            }
        }

        round++;
    }

    if (stop == 0)
        cout << "ENERGY LEFT: " << N;

    return 0;
}