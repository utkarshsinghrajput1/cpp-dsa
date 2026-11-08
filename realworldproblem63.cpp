// 63. Space Mission Signal
// Problem
// Signal number K rounds tak transform hoga.

// Har round:
// - Digit sum = S
// - Total divisors = D
// Rules:
// - D > S → N = N + D
// - D < S → N = N - S
// - D == S → N = N + S + D
// Stop if palindrome.
#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int round = 1;
    int stop = 0;

    while (round <= K && stop == 0) {

        int temp = N;
        int S = 0;

        while (temp > 0) {
            S = S + temp % 10;
            temp = temp / 10;
        }

        int D = 0;

        for (int d = 1; d <= N; d++) {
            if (N % d == 0)
                D++;
        }

        if (D > S)
            N = N + D;
        else if (D < S)
            N = N - S;
        else
            N = N + S + D;

        if (N <= 0) {
            cout << "SIGNAL LOST";
            stop = 1;
        } else {
            temp = N;
            int reverse = 0;

            while (temp > 0) {
                reverse = reverse * 10 + temp % 10;
                temp = temp / 10;
            }

            if (reverse == N) {
                cout << "SIGNAL FOUND: " << N;
                stop = 1;
            }
        }

        round++;
    }

    if (stop == 0)
        cout << "FINAL SIGNAL: " << N;

    return 0;
}