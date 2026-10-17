// Question 19: Digit-Sum Product Hunter
// A aur B ke beech har number N ke liye:
// 1. Digits ka sum calculate karo.
// 2. Digits ka product calculate karo.
// 3. Check karo ki N ka digit sum aur product dono non-zero hain.
// 4. Agar N = digit sum × digit product, toh number print karo.
// Example: N = 22
// Digit sum = 4, digit product = 4, product = 16; match nahi karta.
// Tumhe poori range mein saare matches find karne hain.
// Concept: outer for loop, nested while loop, arithmetic and conditions.

// Task: Range [A, B] mein woh numbers print karo jinke liye N = digit sum × digit product.
#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    if (A > B || A < 0) {
        cout << "INVALID";
        return 0;
    }

    for (int n = A; n <= B; n++) {
        int temp = n;
        int sum = 0;
        int product = 1;

        // Har digit ka sum aur product calculate karo
        if (temp == 0) {
            sum = 0;
            product = 0;
        } else {
            while (temp > 0) {
                int digit = temp % 10;
                sum += digit;
                product *= digit;
                temp /= 10;
            }
        }

        if (sum > 0 && product > 0 &&
            n == sum * product) {
            cout << n << "\n";
        }
    }

    return 0;
}

// Logic: Outer for har number check karta hai. Inner while us number ke digits process karta hai. Last mein equation check hoti hai.
