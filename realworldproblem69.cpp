// 69. Emergency Rescue Code
// Problem
// Code repeatedly transform hoga K rounds tak.

// Har round:
// - Odd digit sum = O
// - Even digit sum = E
// - Divisor count = D
// Rules:
// - O > E → N = N + O - D
// - E > O → N = N + E - D
// - E == O → N = N + D
// Agar number palindrome → RESCUE SUCCESS.
#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int round = 1;
    int stop = 0;

    while (round <= K && stop == 0) {

        int temp = N;
        int oddSum = 0;
        int evenSum = 0;

        while (temp > 0) {
            int digit = temp % 10;

            if (digit % 2 == 0)
                evenSum = evenSum + digit;
            else
                oddSum = oddSum + digit;

            temp = temp / 10;
        }

        int divisors = 0;

        for (int d = 1; d <= N; d++) {
            if (N % d == 0)
                divisors++;
        }

        if (oddSum > evenSum)
            N = N + oddSum - divisors;
        else if (evenSum > oddSum)
            N = N + evenSum - divisors;
        else
            N = N + divisors;

        if (N <= 0) {
            cout << "RESCUE FAILED";
            stop = 1;
        } else {
            temp = N;
            int reverse = 0;

            while (temp > 0) {
                reverse = reverse * 10 + temp % 10;
                temp = temp / 10;
            }

            if (reverse == N) {
                cout << "RESCUE SUCCESS: " << N;
                stop = 1;
            }
        }

        round++;
    }

    if (stop == 0)
        cout << "MISSION ENDED: " << N;

    return 0;
}