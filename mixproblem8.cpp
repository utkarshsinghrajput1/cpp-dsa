// 8. Happy Number — Detect the Cycle
// Hard
// Question: Ek number lo. Uske digits ke squares add karte raho. Agar number 1 ban jaaye, toh Happy Number hai. Agar numbers repeat hote rahein aur 1 na aaye, toh cycle hai.
// Example: 19 → 82 → 68 → 100 → 1

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int current = n;
    int steps = 0;

    // Floyd cycle detection: slow 1 step, fast 2 steps
    int slow = n;
    int fast = n;

    do {
        int sum = 0;
        int temp = slow;

        // Slow ka next number calculate karo
        while (temp > 0) {
            int digit = temp % 10;
            sum += digit * digit;
            temp /= 10;
        }
        slow = sum;

        // Fast ke do transformations
        for (int j = 0; j < 2; j++) {
            int total = 0;
            int x = fast;

            while (x > 0) {
                int digit = x % 10;
                total += digit * digit;
                x /= 10;
            }

            fast = total;
        }

    } while (slow != fast);

    if (slow == 1) {
        cout << "Happy Number";
    } else {
        cout << "Cycle detected: Not Happy";
    }

    return 0;
}

// Seekhne wali baat: Cycle detect karne ke liye do variables ko different speeds par chalana.
