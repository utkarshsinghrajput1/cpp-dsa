// Question: The Ultimate Number Survival Challenge
// Difficulty: 10/10 — Logic Building
// Problem statement
// Ek positive integer N diya hai. Tumhe us number ko repeatedly transform karna hai, maximum K rounds tak.

// Har round mein:
// 1. N ke saare proper divisors ka sum S calculate karo. Proper divisors woh positive divisors hain jo N se chhote hain.
// 2. N ke digits mein se even digits ka sum E aur odd digits ka sum O calculate karo.
// 3. Ab in rules ko isi order mein apply karo:
// - Agar S > N aur E > O, toh naya number N = S - E.
// - Agar S > N aur E <= O, toh naya number N = S - O.
// - Agar S < N aur E > O, toh naya number N = N - E.
// - Agar S < N aur E <= O, toh naya number N = N - O.
// - Agar S == N, toh naya number N = N + E + O.
// 4. Agar naya number 0 ya negative ho jaye, toh print NUMBER DESTROYED aur program stop karo.
// 5. Agar naya number prime ho jaye, toh print NUMBER SURVIVED aur program stop karo.
// 6. Agar K rounds complete ho jayein aur koi stopping condition na aaye, toh final number print karo.
// Prime check aur divisor sum ke liye bhi sirf loops aur if-else use karne hain.


#include <iostream>
using namespace std;

int main() {
    int N, K;

    cout << "Enter N and K: ";
    cin >> N >> K;

    int round = 1;
    bool stopped = false;

    while (round <= K && stopped == false) {

        // Step 1: Find the sum of proper divisors
        int S = 0;

        for (int d = 1; d < N; d++) {
            if (N % d == 0) {
                S = S + d;
            }
        }

        // Step 2: Find the sum of even and odd digits
        int temp = N;
        int E = 0;
        int O = 0;

        while (temp > 0) {
            int digit = temp % 10;

            if (digit % 2 == 0) {
                E = E + digit;
            } else {
                O = O + digit;
            }

            temp = temp / 10;
        }

        // Step 3: Apply the transformation rules
        int nextN;

        if (S > N) {
            if (E > O) {
                nextN = S - E;
            } else {
                nextN = S - O;
            }
        } else if (S < N) {
            if (E > O) {
                nextN = N - E;
            } else {
                nextN = N - O;
            }
        } else {
            nextN = N + E + O;
        }

        cout << "Round " << round
             << ": " << N << " -> " << nextN << endl;

        // Step 4: Check whether the number is destroyed
        if (nextN <= 0) {
            cout << "NUMBER DESTROYED" << endl;
            stopped = true;
        } else {

            // Step 5: Check whether the new number is prime
            int divisors = 0;

            for (int d = 1; d <= nextN; d++) {
                if (nextN % d == 0) {
                    divisors++;
                }
            }

            if (divisors == 2) {
                cout << "NUMBER SURVIVED" << endl;
                cout << "Prime number: " << nextN << endl;
                stopped = true;
            } else {
                N = nextN;
                round++;
            }
        }
    }

    // Step 6: If all rounds finish without stopping
    if (stopped == false) {
        cout << "FINAL NUMBER: " << N << endl;
    }

    return 0;
}

// Round 1: N = 12
// - Proper divisors: 1, 2, 3, 4, 6
// - S = 16
// - Even digits: 2, so E = 2
// - Odd digits: 1, so O = 1
// - Since S > N and E > O, new number is 16 - 2 = 14.
// Correction: The actual first round is 12 -> 14, not 12 -> 9. Let's follow the actual rules:

// Round 1: 12 -> 14
// - Proper divisor sum: 16
// - E = 2, O = 1
// - S > N and E > O, so nextN = 16 - 2 = 14.
// Round 2: 14 -> 10
// - Proper divisors: 1, 2, 7; S = 10
// - E = 4, O = 1
// - S < N and E > O, so nextN = 14 - 4 = 10.
// Round 3: 10 -> 9
// - Proper divisors: 1, 2, 5; S = 8
// - E = 0, O = 1
// - S < N and E <= O, so nextN = 10 - 1 = 9.
// Round 4: 9 -> 5
// - Proper divisors: 1, 3; S = 4
// - E = 0, O = 9
// - S < N and E <= O, so nextN = 9 - 9 = 0.
// - The number is destroyed, so the program stops here.