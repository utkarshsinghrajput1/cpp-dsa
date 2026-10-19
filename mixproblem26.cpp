// Question 1 — The Number Kingdom's Final Battle
// Difficulty: 10/10
// Problem: Ek positive integer N aur maximum rounds K diye gaye hain.

// Har round mein:
// 1. N ke proper divisors ka sum S nikalo.
// 2. N ke digits ka even sum E aur odd sum O nikalo.
// 3. N ke total digits mein se kitne digits 3 se divisible hain, unka count C nikalo.
// 4. Transformation rules:
//    - Agar S > N, toh N = S - E + C.
//    - Agar S < N, toh N = N - O - C.
//    - Agar S == N, toh N = N + E + O + C.
// 5. Naya number 0 ya negative ho, toh DESTROYED print karo.
// 6. Naya number prime ho, toh SURVIVED print karo.
// 7. Warna agla round continue karo. Maximum K rounds ke baad final number print karo.

#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int round = 1;
    int stopped = 0;

    while (round <= K && stopped == 0) {
        int S = 0;

        // Find the sum of proper divisors
        for (int d = 1; d < N; d++) {
            if (N % d == 0) {
                S = S + d;
            }
        }

        // Calculate even sum E, odd sum O, and count C
        int temp = N;
        int E = 0, O = 0, C = 0;

        while (temp > 0) {
            int digit = temp % 10;

            if (digit % 2 == 0) {
                E = E + digit;
            } else {
                O = O + digit;
            }

            if (digit % 3 == 0) {
                C++;
            }

            temp = temp / 10;
        }

        int nextN;

        if (S > N) {
            nextN = S - E + C;
        } else if (S < N) {
            nextN = N - O - C;
        } else {
            nextN = N + E + O + C;
        }

        cout << "Round " << round << ": "
             << N << " -> " << nextN << endl;

        if (nextN <= 0) {
            cout << "DESTROYED" << endl;
            stopped = 1;
        } else {
            // Count the divisors of nextN
            int divisors = 0;

            for (int d = 1; d <= nextN; d++) {
                if (nextN % d == 0) {
                    divisors++;
                }
            }

            if (divisors == 2) {
                cout << "SURVIVED" << endl;
                cout << "Prime number: " << nextN << endl;
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
// Logic samajh: Har round mein pehle divisor sum aur digit calculations hote hain. Uske baad conditions decide karti hain ki number kaise change hoga. Phir nested logic nahi, balki ek separate for loop new number ke divisors count karta hai. Exactly 2 divisors hone par number prime hai.
