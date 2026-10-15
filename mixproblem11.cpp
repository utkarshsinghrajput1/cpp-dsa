// 11. The Collatz Escape Challenge
// Very Hard
// Question: Ek positive integer N lo. Agar number even hai toh usko 2 se divide karo. Agar odd hai toh 3 se multiply karke 1 add karo. Jab tak 1 na aaye, process repeat karo. Total steps aur sabse bada number find karo jo process mein aaya.
// Example: N = 7
// 7 → 22 → 11 → 34 → 17 → 52 → 26 → 13
// → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

// Steps = 16
// Maximum = 52

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    int steps = 0;
    long long maximum = n;

    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }

        steps++;

        // Har naye number ko maximum se compare karo
        if (n > maximum) {
            maximum = n;
        }
    }

    cout << "Steps = " << steps << endl;
    cout << "Maximum = " << maximum;

    return 0;
}

// Challenge: Aisa number dhoondo jo 1 tak pahunchne se pehle bahut zyada steps leta ho. Bahut bade inputs par overflow ho sakta hai, isliye input carefully choose karna.
