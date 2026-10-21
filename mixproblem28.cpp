// Question — The Three-Divisor Mystery
// Difficulty: 9.5/10
// Problem: L aur R ke beech saare numbers find karo jo ye conditions satisfy karte hain:
// - Number ke exactly 3 positive divisors hone chahiye.
// - Uske proper divisors ka sum even hona chahiye.
// - Uske digits ka sum odd hona chahiye.
// - Number ke digits mein kam se kam ek 0 nahi, balki exactly one digit 5 hona chahiye.
// End mein qualifying numbers ki count print karo.


#include <iostream>
using namespace std;

int main() {
    int L, R;
    cin >> L >> R;

    int total = 0;

    for (int n = L; n <= R; n++) {
        int divisorCount = 0;
        int properSum = 0;

        // Count divisors and sum proper divisors
        for (int d = 1; d <= n; d++) {
            if (n % d == 0) {
                divisorCount++;

                if (d < n) {
                    properSum = properSum + d;
                }
            }
        }

        int temp = n;
        int digitSum = 0;
        int fiveCount = 0;

        // Inspect every digit
        while (temp > 0) {
            int digit = temp % 10;

            digitSum = digitSum + digit;

            if (digit == 5) {
                fiveCount++;
            }

            temp = temp / 10;
        }

        if (divisorCount == 3 &&
            properSum % 2 == 0 &&
            digitSum % 2 != 0 &&
            fiveCount == 1) {

            cout << n << " ";
            total++;
        }
    }

    cout << endl;
    cout << "Total: " << total << endl;

    return 0;
}




// Hinglish explanation:
// - divisorCount == 3 means exactly three divisors.
// - properSum % 2 == 0 means proper-divisor sum even hai.
// - digitSum % 2 != 0 means digit sum odd hai.
// - fiveCount == 1 ensures digit 5 exactly ek baar aata hai.
// Bhai, challenge yeh hai ki chaar independent conditions ko ek saath correct order mein verify karna hai.


