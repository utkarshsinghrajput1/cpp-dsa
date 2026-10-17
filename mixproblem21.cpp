// 1. The Number That Escapes Its Own Divisors
// Problem statement
// Ek integer N diya hai. N se shuru karke har number x ke liye uske proper divisors ka sum calculate karo — yani x ko chhodkar uske sabhi positive divisors ka sum.
// Phir:
// - Agar divisor sum x ke barabar hai, toh PERFECT print karo.
// - Agar sum x se chhota hai, toh x ko x + sum bana do.
// - Agar sum x se bada hai, toh x ko sum - x bana do.
// - Har transformation ke baad naye number par same process chalao.
// - Agar number 1 ban jaaye, REACHED 1 print karo.
// - Agar number N se bada ho jaaye, ESCAPED print karo.
// - Maximum K transformations ke baad bhi result na mile, toh LIMIT REACHED print karo.
// Input: N K
// Example:
// Input:
// 12 5
// Exact sequence aur final output find karna.
// Skills: nested loops, divisor sums, state transitions, multiple stopping conditions
#include <iostream>
using namespace std;

int main() {
    long long N;
    int K;
    cin >> N >> K;

    if (N <= 0 || K < 0) {
        cout << "INVALID";
        return 0;
    }

    long long x = N;
    int steps = 0;

    while (steps < K) {

        // Step 1: Proper divisors ka sum calculate karo.
        // Proper divisors woh hote hain jo x ko divide karte hain,
        // lekin x khud include nahi hota.

        long long sum = 0;

        for (long long d = 1; d < x; d++) {
            if (x % d == 0) {
                sum += d;
            }
        }

        // Step 2: Check karo ki number perfect hai ya nahi.
        if (sum == x) {
            cout << "PERFECT";
            return 0;
        }

        // Step 3: Number 1 ban gaya toh stop.
        if (x == 1) {
            cout << "REACHED 1";
            return 0;
        }

        // Step 4: Transformation rules apply karo.
        if (sum < x) {
            x = x + sum;
        } else {
            x = sum - x;
        }

        steps++;

        // Step 5: Original N se bada ho gaya toh escape.
        if (x > N) {
            cout << "ESCAPED";
            return 0;
        }

        // Step 6: Transformation ke baad 1 mila toh stop.
        if (x == 1) {
            cout << "REACHED 1";
            return 0;
        }
    }

    // K transformations ke baad bhi condition satisfy nahi hui.
    cout << "LIMIT REACHED";

    return 0;
}