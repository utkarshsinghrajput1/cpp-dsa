// Question 20: The Digit Kingdom
// Ek number N diya hai. Number ko tab tak transform karo jab tak ek digit na bache, lekin har round mein:
// - Even digits ka sum nikalo.
// - Odd digits ka product nikalo.
// - Agar even-digit sum prime hai, toh usse odd-digit product mein add karo.
// - Warna odd-digit product mein se even-digit sum subtract karo.
// - Agar odd digits hi nahi hain, toh odd-digit product ko 1 maana jayega.
// - Agar result zero ya negative ho, toh process stop karo.
// Example:

// N = 1234

// Even digits: 2, 4
// Even sum = 6

// Odd digits: 1, 3
// Odd product = 3

// 6 prime nahi hai
// Result = 3 - 6 = -3

// Output: STOPPED

// Challenge: Har round mein naye number ke digits process karne hain, prime check karna hai aur termination conditions handle karni hain.
// Concept: nested while + for loops, prime checking, digit arithmetic, multiple conditions.


// Task: Even digits ka sum aur odd digits ka product calculate karo. Even sum prime ho toh add karo, warna subtract karo. Result ko next round ka number banao.

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n <= 0) {
        cout << "STOPPED";
        return 0;
    }

    while (n >= 10) {
        long long temp = n;
        int evenSum = 0;
        long long oddProduct = 1;
        bool hasOdd = false;

        // Digits process karo
        while (temp > 0) {
            int digit = temp % 10;

            if (digit % 2 == 0) {
                evenSum += digit;
            } else {
                oddProduct *= digit;
                hasOdd = true;
            }

            temp /= 10;
        }

        // Agar odd digit nahi hai, product 1 maana jayega
        if (!hasOdd)
            oddProduct = 1;

        // Even sum prime hai ya nahi check karo
        bool prime = true;

        if (evenSum < 2)
            prime = false;

        for (int d = 2; d * d <= evenSum; d++) {
            if (evenSum % d == 0) {
                prime = false;
                break;
            }
        }

        long long next;

        if (prime)
            next = oddProduct + evenSum;
        else
            next = oddProduct - evenSum;

        if (next <= 0) {
            cout << "STOPPED";
            return 0;
        }

        n = next;
    }

    cout << n;
    return 0;
}
// Logic: 2 + 4 = 6, jo prime nahi hai. Odd digits ka product 1 × 3 = 3. Result 3 - 6 = -3, isliye process stop ho jaata hai.
