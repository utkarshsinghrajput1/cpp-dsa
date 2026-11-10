// 70. FINAL BOSS — Smart City Master Scanner
// Difficulty: EXTREME / FINAL BOSS
// Problem
// L se R tak har city ID n check karo.

// Ek ID MASTER ID hogi agar:
// Condition 1
// n composite ho.
// Condition 2
// Original number ke:
// - even digit sum = E
// - odd digit sum = O
// Condition 3
// Har divisor d ke liye:
// - d ka digit sum calculate karo
// - Agar divisor digit sum even hai → evenSpecial++
// - Agar odd hai → oddSpecial++
// Condition 4
// Proper divisors ka sum S nikalo.
// Final qualification

// E > O
// AND
// evenSpecial > oddSpecial
// AND
// S % (E + O) == 0
// AND
// number palindrome nahi hai


#include <iostream>
using namespace std;

int main() {
    int L, R;
    cin >> L >> R;

    int total = 0;

    // Check every City ID
    for (int n = L; n <= R; n++) {

        // -----------------------------
        // STEP 1: Check digits of n
        // -----------------------------
        int temp = n;

        int evenSum = 0;
        int oddSum = 0;
        int reverse = 0;

        while (temp > 0) {
            int digit = temp % 10;

            // Separate even and odd digit sums
            if (digit % 2 == 0)
                evenSum = evenSum + digit;
            else
                oddSum = oddSum + digit;

            // Build reverse number
            reverse = reverse * 10 + digit;

            temp = temp / 10;
        }

        // -----------------------------
        // STEP 2: Find all divisors
        // -----------------------------
        int divisorCount = 0;
        int properSum = 0;

        int evenSpecial = 0;
        int oddSpecial = 0;

        for (int d = 1; d <= n; d++) {

            if (n % d == 0) {

                divisorCount++;

                // n itself is NOT a proper divisor
                if (d < n)
                    properSum = properSum + d;

                // --------------------------------
                // STEP 3: Find digit sum of divisor
                // --------------------------------
                int x = d;
                int divisorDigitSum = 0;

                while (x > 0) {
                    divisorDigitSum =
                        divisorDigitSum + x % 10;

                    x = x / 10;
                }

                // Separate divisor types
                if (divisorDigitSum % 2 == 0)
                    evenSpecial++;
                else
                    oddSpecial++;
            }
        }

        // -----------------------------
        // STEP 4: Composite check
        // Composite => more than 2 divisors
        // -----------------------------

        if (divisorCount > 2) {

            // Original number should NOT be palindrome
            if (reverse != n) {

                // Even digit sum must be greater
                if (evenSum > oddSum) {

                    // More even-sum divisors required
                    if (evenSpecial > oddSpecial) {

                        int totalDigitSum =
                            evenSum + oddSum;

                        // Avoid division by zero
                        if (totalDigitSum > 0) {

                            if (properSum %
                                totalDigitSum == 0) {

                                cout << n
                                     << " is MASTER ID"
                                     << endl;

                                total++;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << endl;
    cout << "Total MASTER IDs: "
         << total << endl;

    return 0;
}