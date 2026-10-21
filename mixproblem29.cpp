// Question - The number reactor
// Problem: Input mein positive number N aur rounds K diye gaye hain.

// Har round:
// 1. N ke total divisors ka count C nikalo.
// 2. Even digits ka sum E aur odd digits ka count O nikalo.
// 3. Agar C odd hai, toh nextN = N + E + C.
// 4. Agar C even hai, toh nextN = N - O - C.
// 5. Agar nextN <= 0, print REACTOR FAILED.
// 6. Agar nextN exactly 7 se divisible hai aur uske exactly 4 divisors hain, print SPECIAL LOCK OPENED aur stop.
// 7. Otherwise next round continue karo. K rounds ke baad final number print karo.

#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int round = 1;
    int stopped = 0;

    while (round <= K && stopped == 0) {
        int C = 0;

        // Count all divisors of N
        for (int d = 1; d <= N; d++) {
            if (N % d == 0) {
                C++;
            }
        }

        int temp = N;
        int E = 0;
        int O = 0;

        // Calculate even-digit sum and odd-digit count
        while (temp > 0) {
            int digit = temp % 10;

            if (digit % 2 == 0) {
                E = E + digit;
            } else {
                O++;
            }

            temp = temp / 10;
        }

        int nextN;

        if (C % 2 != 0) {
            nextN = N + E + C;
        } else {
            nextN = N - O - C;
        }

        cout << "Round " << round << ": "
             << N << " -> " << nextN << endl;

        if (nextN <= 0) {
            cout << "REACTOR FAILED" << endl;
            stopped = 1;
        } else {
            int newDivisors = 0;

            // Count divisors of the new number
            for (int d = 1; d <= nextN; d++) {
                if (nextN % d == 0) {
                    newDivisors++;
                }
            }

            if (nextN % 7 == 0 && newDivisors == 4) {
                cout << "SPECIAL LOCK OPENED" << endl;
                cout << "Final number: " << nextN << endl;
                stopped = 1;
            } else {
                N = nextN;
                round++;
            }
        }
    }

    if (stopped == 0) {
        cout << "FINAL NUMBER: " << N << endl;
    }

    return 0;
}

// Is question mein pehle divisor count ki parity check hoti hai — yani C odd hai ya even. Uske according number increase ya decrease hota hai.

// Phir naya number dobara check hota hai: kya woh 7 se divisible hai aur uske exactly 4 divisors hain? Dono conditions true hui toh reactor unlock ho jayega.
