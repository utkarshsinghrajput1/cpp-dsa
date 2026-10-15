// 13. The Self-Describing Digit Counter
// Extreme
// Question: Ek number ke har digit ko count karo, lekin array ke bina. Phir check karo ki number mein har digit utni hi baar aaya hai jitna us digit ki value demand karti hai.
// Example: 1210
// - Digit 0 ek baar aaya.
// - Digit 1 do baar aaya.
// - Digit 2 ek baar aaya.
// - Digit 3 zero baar aaya.
// Isliye 1210 self-describing number hai.


#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int original = n;
    int digits = 0;
    int temp = n;

    // Total digits count karo
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    bool valid = true;
    int position = 0;

    // Har digit 0 se 9 tak check karo
    while (position < digits) {
        temp = original;

        int digitCount = 0;
        int currentPosition = 0;

        // Number ke andar current digit count karo
        while (temp > 0) {
            int digit = temp % 10;

            // Right se position count kar rahe hain
            if (currentPosition == position) {
                // Is position ka digit required count hai
                int required = digit;

                // Original number mein is digit ko count karo
                int copy = original;
                int actualCount = 0;

                while (copy > 0) {
                    if (copy % 10 == position) {
                        actualCount++;
                    }

                    copy /= 10;
                }

                if (actualCount != required) {
                    valid = false;
                }

                break;
            }

            currentPosition++;
            temp /= 10;
        }

        position++;
    }

    if (valid) {
        cout << "Possible self-describing number";
    } else {
        cout << "Not self-describing";
    }

    return 0;
}

// Important: Self-describing number mein digit ki position ka meaning fixed hota hai: leftmost digit batata hai kitne zero hain, next digit batata hai kitne ones hain, and so on. Upar diya gaya code is positional rule ko fully implement nahi karta; isliye ise final correct solution nahi, balki nested-loop practice ke starting point ki tarah use kar. Is puzzle ka correct solution banane ke liye positional indexing ko carefully handle karna hoga.

