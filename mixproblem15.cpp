// Question 15: The Self-Transforming Number
// Ek positive integer N lo. Har round mein uske digits ke squares ka sum nikalo. Jo sum mile, us par wahi process repeat karo.
// Program ko identify karna hai ki number 1 tak pahunchta hai ya nahi. Agar koi number repeat ho jaaye, toh cycle detect karo.
// Example:
// N = 19

// 1² + 9² = 82
// 8² + 2² = 68
// 6² + 8² = 100
// 1² + 0² + 0² = 1

// Output: REACHES 1
// Challenge: Arrays aur strings ke bina cycle detect karne ka logic sochna.
// Concept: nested while loops, digit processing, cycle detection.
// Task: Har round mein digits ke squares ka sum nikalo. Check karo ki number 1 tak pahunchta hai ya nahi, ya phir koi cycle banata hai.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "INVALID";
        return 0;
    }

    int slow = n;
    int fast = n;

    // Floyd cycle detection:
    // slow ek transformation karta hai,
    // fast do transformations karta hai.

    while (true) {
        // Slow ka ek step
        int sum = 0;
        int temp = slow;

        while (temp > 0) {
            int digit = temp % 10;
            sum += digit * digit;
            temp /= 10;
        }

        slow = sum;

        // Fast ka pehla step
        sum = 0;
        temp = fast;

        while (temp > 0) {
            int digit = temp % 10;
            sum += digit * digit;
            temp /= 10;
        }

        fast = sum;

        // Fast ka doosra step
        sum = 0;
        temp = fast;

        while (temp > 0) {
            int digit = temp % 10;
            sum += digit * digit;
            temp /= 10;
        }

        fast = sum;

        if (slow == 1 || fast == 1) {
            cout << "REACHES 1";
            break;
        }

        if (slow == fast) {
            cout << "CYCLE DETECTED";
            break;
        }
    }

    return 0;
}
// Logic: slow ek step aur fast do steps leta hai. Agar dono equal ho jaate hain aur 1 nahi mila, toh cycle hai.