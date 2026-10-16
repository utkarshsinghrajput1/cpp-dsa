// Question 17: Reverse-Add Number Trap
// Number N lo. Uska reverse nikalo aur dono ko add karo. Phir sum ko reverse karke dobara add karo. Jab tak palindrome na mile, process continue karo.
// Example:
// N = 56

// 56 + 65 = 121

// Output: 121
// Rounds: 1
// Agar K rounds mein palindrome nahi milta, toh NOT FOUND print karo.
// Condition: N aur K input honge; overflow se bachne ke liye input range define karna tumhari responsibility hai.
// Concept: nested while loops, reversing, palindrome check, round counting.

// Task: Number ko reverse karke add karo, jab tak palindrome mile ya K rounds complete ho jaayein.
#include <iostream>
using namespace std;

int main() {
    long long n;
    int K;
    cin >> n >> K;

    if (n < 0 || K < 0) {
        cout << "INVALID";
        return 0;
    }

    int rounds = 0;

    while (rounds < K) {
        long long temp = n;
        long long rev = 0;

        // Number reverse karo
        while (temp > 0) {
            int digit = temp % 10;
            rev = rev * 10 + digit;
            temp /= 10;
        }

        // Check karo ki current number palindrome hai ya nahi
        if (rev == n) {
            cout << n << "\nRounds: " << rounds;
            return 0;
        }

        // Overflow se bachne ke liye simple boundary check
        if (n > 1000000000000000000LL - rev) {
            cout << "OVERFLOW RISK";
            return 0;
        }

        n += rev;
        rounds++;
    }

    // Last round ke baad bhi palindrome ho sakta hai
    long long temp = n;
    long long rev = 0;

    while (temp > 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }

    if (rev == n)
        cout << n << "\nRounds: " << rounds;
    else
        cout << "NOT FOUND";

    return 0;
}
