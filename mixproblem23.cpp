// Question 2 — The Three-Engine Countdown
// Difficulty: 10/10
// Boss

// Teen positive integers A, B, C aur target T diye gaye hain.
// Har round mein teeno numbers ke naye values calculate karo:
// - Engine A: A ke digits ka sum nikalo, phir usse A mein add karo.
// - Engine B: B ke digits ka product nikalo, phir usse B mein add karo.
// - Engine C: C ka sabse bada digit nikalo, phir usse C mein add karo.
// Race tab tak chalegi jab tak koi number T se bada na ho jaaye.
// - Sirf A cross kare: A WINS
// - Sirf B cross kare: B WINS
// - Sirf C cross kare: C WINS
// - Ek hi round mein do ya teen numbers cross karein: TIE
// Input: A B C T
// Example input:


#include <iostream>
using namespace std;

int main() {
    long long A, B, C, T;
    cin >> A >> B >> C >> T;

    if (A <= 0 || B <= 0 || C <= 0 || T <= 0) {
        cout << "INVALID";
        return 0;
    }

    int rounds = 0;

    // Har round mein teeno numbers ko update karenge.
    // Sabhi updates ek hi round ke original values se calculate honge.

    while (A <= T && B <= T && C <= T) {

        // --------------------------------
        // ENGINE A: Digit sum
        // --------------------------------

        long long temp = A;
        long long digitSum = 0;

        while (temp > 0) {
            int digit = temp % 10;
            digitSum += digit;
            temp /= 10;
        }

        long long nextA = A + digitSum;

        // --------------------------------
        // ENGINE B: Digit product
        // --------------------------------

        temp = B;
        long long digitProduct = 1;

        while (temp > 0) {
            int digit = temp % 10;
            digitProduct *= digit;
            temp /= 10;
        }

        long long nextB = B + digitProduct;

        // --------------------------------
        // ENGINE C: Largest digit
        // --------------------------------

        temp = C;
        int largestDigit = 0;

        while (temp > 0) {
            int digit = temp % 10;

            if (digit > largestDigit) {
                largestDigit = digit;
            }

            temp /= 10;
        }

        long long nextC = C + largestDigit;

        // Ek round complete: teeno values update karo.
        A = nextA;
        B = nextB;
        C = nextC;

        rounds++;
    }

    // Ab pata karo kaun-kaun target cross kar chuka hai.
    bool aWins = (A > T);
    bool bWins = (B > T);
    bool cWins = (C > T);

    // true ka value 1 aur false ka value 0 hota hai.
    int winners = aWins + bWins + cWins;

    if (winners > 1) {
        cout << "TIE\n";
    } else if (aWins) {
        cout << "A WINS\n";
    } else if (bWins) {
        cout << "B WINS\n";
    } else if (cWins) {
        cout << "C WINS\n";
    }

    cout << "Rounds: " << rounds << "\n";
    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    cout << "C = " << C << "\n";

    return 0;
}

// First round:
// - A: 19 + (1 + 9) = 29
// - B: 23 + (2 × 3) = 29
// - C: 17 + 7 = 24
// Ab numbers 29, 29, 24 hain. Agle round mein dobara unke digits process honge.
// Ye process tab tak chalega jab tak koi number 100 cross na kare.
// Sabse important concept: nextA, nextB, nextC alag variables mein rakhne se teeno engines ka update ek hi round ke starting values par based rehta hai.
