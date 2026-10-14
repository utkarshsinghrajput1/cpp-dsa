// 10. Reverse-and-Add Number — Palindrome Convergence
// Very Hard
// Question: Number reverse karo aur original mein add karo. Repeat karo jab tak palindrome mil jaaye ya maximum steps complete ho jaayein.
// Example: 56 → 56 + 65 = 121, jo palindrome hai.

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    int steps = 0;
    int limit = 20;

    while (steps < limit) {
        long long temp = n;
        long long reversed = 0;

        // Number reverse karo
        while (temp > 0) {
            reversed = reversed * 10 + temp % 10;
            temp /= 10;
        }

        // Check karo ki current number palindrome hai ya nahi
        if (n == reversed) {
            cout << "Palindrome = " << n << endl;
            cout << "Steps = " << steps;
            return 0;
        }

        // Reverse-and-add operation
        n = n + reversed;
        steps++;
    }

    cout << "Palindrome not found within " << limit << " steps";

    return 0;
}


// Seekhne wali baat: Har iteration mein number change hota hai. Loop ko limit karna bhi important hai, taaki program indefinitely na chale.
