// Question    — The Ultimate Number Pair Hunter
// Problem: Do integers L aur R diye gaye hain. Har possible pair (a, b) check karo, jahan L <= a < b <= R.

// Pair tab valid hoga jab:
// 1. a ke proper divisors ka sum, b ke digits ke sum ke equal ho.
// 2. b ke total divisors ka count, a ke digits ke sum ke equal ho.
// 3. a + b odd ho.
// 4. Dono numbers composite hon.
// Saare valid pairs print karo aur total valid pairs ki count batao.

#include <iostream>
using namespace std;

int main() {
    int L, R;
    cin >> L >> R;

    int totalPairs = 0;

    // Generate every possible pair a < b
    for (int a = L; a <= R; a++) {
        for (int b = a + 1; b <= R; b++) {

            int properSumA = 0;
            int divisorsA = 0;
            int divisorsB = 0;

            // Find proper divisor sum and divisor count of a
            for (int d = 1; d <= a; d++) {
                if (a % d == 0) {
                    divisorsA++;

                    if (d < a) {
                        properSumA = properSumA + d;
                    }
                }
            }

            // Count divisors of b
            for (int d = 1; d <= b; d++) {
                if (b % d == 0) {
                    divisorsB++;
                }
            }

            // Calculate digit sum of a
            int tempA = a;
            int digitSumA = 0;

            while (tempA > 0) {
                digitSumA = digitSumA + tempA % 10;
                tempA = tempA / 10;
            }

            // Calculate digit sum of b
            int tempB = b;
            int digitSumB = 0;

            while (tempB > 0) {
                digitSumB = digitSumB + tempB % 10;
                tempB = tempB / 10;
            }

            // Both numbers must be composite
            if (divisorsA > 2 &&
                divisorsB > 2 &&
                properSumA == digitSumB &&
                divisorsB == digitSumA &&
                (a + b) % 2 != 0) {

                cout << "(" << a << ", " << b << ")" << endl;
                totalPairs++;
            }
        }
    }

    cout << "Total valid pairs: " << totalPairs << endl;

    return 0;
}

// Yeh sabse difficult question hai kyunki tumhe har possible pair generate karna hai. Iske liye do nested for loops hain:
// - Outer loop a choose karta hai.
// - Inner loop usse bada b choose karta hai.
// - Phir har pair ke divisor counts, proper-divisor sum aur digit sums calculate hote hain.
// - Last mein saari conditions ek saath verify hoti hain.
// Important: Ye programs practice ke liye small inputs par run karna, jaise L = 1, R = 100. Inmein divisor-checking ke liye nested loops hain, isliye bahut bade ranges par execution slow ho sakta hai.
