// 58. Digital Locker Mystery
// Problem
// Locker code unlock hoga agar:
// - Har digit ka count exactly 1 ya 2 ho
// - Koi digit 3 ya zyada baar nahi hona chahiye
// - Code composite ho
#include <iostream>
using namespace std;

int main() {
    int code;
    cin >> code;

    int invalid = 0;

    // Check every possible digit
    for (int target = 0; target <= 9; target++) {

        int temp = code;
        int count = 0;

        while (temp > 0) {
            if (temp % 10 == target)
                count++;

            temp = temp / 10;
        }

        if (count >= 3)
            invalid = 1;
    }

    int divisors = 0;

    for (int d = 1; d <= code; d++) {
        if (code % d == 0)
            divisors++;
    }

    if (invalid == 0 && divisors > 2)
        cout << "UNLOCKED";
    else
        cout << "LOCKED";

    return 0;
}