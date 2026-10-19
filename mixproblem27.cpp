// Question 2 — The Digit-Divisor Tribunal
// Difficulty: 10/10
// Problem: Do numbers L aur R diye gaye hain. Range ke har number n ko test karo.

// Number tab qualify karega jab:
// 1. n ke even digits ka sum E nikalo.
// 2. n ke odd digits ka count Ocount nikalo.
// 3. n ke har divisor d ke digits ka sum nikalo.
// 4. Aise divisors ka count C nikalo jinka digit sum odd hai.
// 5. Number tab qualify karega jab:
//    - C == E
//    - Ocount > 0
//    - n composite ho.
// Saare qualifying numbers print karo aur end mein unki total count print karo.

#include <iostream>
using namespace std;

int main() {
    int L, R;
    cin >> L >> R;

    int total = 0;

    for (int n = L; n <= R; n++) {
        int temp = n;
        int E = 0;
        int Ocount = 0;

        // Calculate even-digit sum and odd-digit count
        while (temp > 0) {
            int digit = temp % 10;

            if (digit % 2 == 0) {
                E = E + digit;
            } else {
                Ocount++;
            }

            temp = temp / 10;
        }

        int C = 0;

        // Check every divisor of n
        for (int d = 1; d <= n; d++) {
            if (n % d == 0) {
                int x = d;
                int digitSum = 0;

                // Calculate digit sum of divisor d
                while (x > 0) {
                    digitSum = digitSum + x % 10;
                    x = x / 10;
                }

                if (digitSum % 2 != 0) {
                    C++;
                }
            }
        }

        // Check whether n is composite
        int divisorCount = 0;

        for (int d = 1; d <= n; d++) {
            if (n % d == 0) {
                divisorCount++;
            }
        }

        if (C == E && Ocount > 0 && divisorCount > 2) {
            cout << n << " ";
            total++;
        }
    }

    cout << endl;
    cout << "Total qualifying numbers: " << total << endl;

    return 0;
}
// Hinglish explanation: Yeh problem nested-loop thinking test karti hai. Outer for har number check karta hai. Uske andar doosra for divisors check karta hai. Divisor milne par while uske digits ka sum calculate karta hai. Last mein conditions verify hoti hain.
