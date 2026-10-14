// 9. Kaprekar Number — The Splitting Trick
// Hard
// Question: Number ka square karo. Square ko do parts mein split karo. Dono parts ka sum original number ke equal ho, toh number Kaprekar Number hai.
// Example: 45² = 2025, aur 20 + 25 = 45.

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long square = n * n;
    long long temp = n;
    long long divisor = 1;

    // Original number mein digits count karo
    while (temp > 0) {
        divisor *= 10;
        temp /= 10;
    }

    // Square ko right aur left parts mein split karo
    long long right = square % divisor;
    long long left = square / divisor;

    if (n > 0 && right > 0 && left + right == n) {
        cout << "Kaprekar Number";
    } else {
        cout << "Not a Kaprekar Number";
    }

    return 0;
}


// Seekhne wali baat: % aur / se number ko split karna. Is definition mein single-digit Kaprekar numbers aur right part zero wale cases ko exclude kiya gaya hai.