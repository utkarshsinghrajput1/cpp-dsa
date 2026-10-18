// Question 3 — The Hidden Divisibility Tournament
// Difficulty: Boss Level
// Extreme

// Do integers L aur R diye gaye hain. Range ke har number ko tournament mein test karna hai.
// Number tab qualify karega jab saari chaar conditions true hon:
// 1. Total divisors ki count odd ho.
// 2. Proper divisors ka sum even ho.
// 3. Digit sum, total divisors ki count se bada ho.
// 4. Number prime na ho.
// Output:
// - Saare qualifying numbers.
// - Qualifying numbers ki total count.
// - Sabse bada qualifying number.
// Example input:

#include <iostream>
using namespace std;

int main() {
    int L, R;
    cin >> L >> R;

    if (L < 1 || L > R) {
        cout << "INVALID";
        return 0;
    }

    int totalQualified = 0;
    int largestQualified = -1;

    // OUTER LOOP:
    // L se R tak har number ko test karo.
    for (int n = L; n <= R; n++) {

        int divisorCount = 0;
        long long properSum = 0;

        // STEP 1: Divisors count aur proper divisor sum.
        for (int d = 1; d <= n; d++) {

            if (n % d == 0) {
                divisorCount++;

                // Number khud proper divisor nahi hota.
                if (d != n) {
                    properSum += d;
                }
            }
        }

        // STEP 2: Digits ka sum calculate karo.
        int temp = n;
        int digitSum = 0;

        while (temp > 0) {
            digitSum += temp % 10;
            temp /= 10;
        }

        // STEP 3: Prime check.
        bool prime = true;

        if (n < 2) {
            prime = false;
        }

        for (int d = 2; d * d <= n; d++) {

            if (n % d == 0) {
                prime = false;
                break;
            }
        }

        // STEP 4: Chaaron conditions check karo.
        if (divisorCount % 2 == 1 &&
            properSum % 2 == 0 &&
            digitSum > divisorCount &&
            prime == false) {

            cout << n << "\n";

            totalQualified++;

            // Sabse bada qualifying number track karo.
            if (n > largestQualified) {
                largestQualified = n;
            }
        }
    }

    // STEP 5: Final results.
    cout << "Total qualifying numbers: "
         << totalQualified << "\n";

    if (totalQualified > 0) {
        cout << "Largest qualifying number: "
             << largestQualified << "\n";
    } else {
        cout << "No qualifying number found\n";
    }

    return 0;
}


// Explanation aur dry run
// Example ke liye n = 49 check karte hain:
// - Divisors: 1, 7, 49
// - Divisor count = 3, jo odd hai.
// - Proper divisor sum = 1 + 7 = 8, jo even hai.
// - Digit sum = 4 + 9 = 13.
// - 13 > 3, aur 49 prime nahi hai.
// Isliye 49 qualify karta hai.
// Code ka main condition:

// if (divisorCount % 2 == 1 &&
//     properSum % 2 == 0 &&
//     digitSum > divisorCount &&
//     prime == false)
// Yahan && ka matlab hai ki chaaron conditions ek saath true honi chahiye.
