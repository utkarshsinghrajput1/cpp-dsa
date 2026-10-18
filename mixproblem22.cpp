// Question 1 — The Mathematical Escape Room
// Difficulty: 10/10
// Extreme

// Ek positive integer N aur maximum rounds K diye gaye hain.
// Har round mein current number x ke liye:
// 1. x ke saare proper divisors ka sum S calculate karo.
// 2. Digits ka sum D calculate karo.
// 3. Agar S > x, toh next number S - D hoga.
// 4. Agar S < x, toh next number x + D hoga.
// 5. Agar S == x, toh PERFECT print karke stop karo.
// 6. Agar next number 0 ya negative ho, toh COLLAPSED print karo.
// 7. Agar next number N se bada ho, toh ESCAPED print karo.
// 8. Maximum K rounds ke baad bhi kuch nahi hua, toh LIMIT REACHED print karo.
// Input: N K
// Example:
// 12 5
// Challenge: Har round mein divisor sum aur digit sum dobara calculate karne hain.

#include <iostream>
using namespace std;

int main() {
    long long N, x;
    int K;

    cin >> N >> K;

    if (N <= 0 || K < 0) {
        cout << "INVALID";
        return 0;
    }

    x = N;
    int rounds = 0;

    while (rounds < K) {

        // STEP 1: Proper divisors ka sum calculate karo.
        // Proper divisor x ko completely divide karta hai,
        // lekin x khud proper divisor nahi hai.

        long long S = 0;

        for (long long d = 1; d < x; d++) {
            if (x % d == 0) {
                S += d;
            }
        }

        // STEP 2: Current number ke digits ka sum.
        long long temp = x;
        long long D = 0;

        while (temp > 0) {
            D += temp % 10;
            temp /= 10;
        }

        // STEP 3: Perfect number check.
        if (S == x) {
            cout << "PERFECT";
            return 0;
        }

        // STEP 4: Rules ke according next number.
        long long next;

        if (S > x) {
            next = S - D;
        } else {
            next = x + D;
        }

        rounds++;

        // STEP 5: Number collapse ho gaya?
        if (next <= 0) {
            cout << "COLLAPSED";
            return 0;
        }

        // STEP 6: Original limit cross hui?
        if (next > N) {
            cout << "ESCAPED";
            return 0;
        }

        // STEP 7: Next round ke liye number update.
        x = next;
    }

    cout << "LIMIT REACHED";
    return 0;
}

// Starting number x = 12.
// - Proper divisors: 1, 2, 3, 4, 6
// - Divisor sum: S = 16
// - Digit sum: D = 1 + 2 = 3
// Since S > x:
// \[
// next = S-D = 16-3 = 13
// \]

// Ab 13 > 12, isliye output:
// Seekhne wali baat: Outer while rounds control karta hai; nested for divisors find karta hai; doosra while digits ka sum nikalta hai.
