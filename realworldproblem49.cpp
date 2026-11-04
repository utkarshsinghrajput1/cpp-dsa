// 9. Smart Door Password Scanner
// Problem
// Password number reject hoga agar:
// - Same digit exactly 2 baar nahi, kisi bhi digit ka count exactly 3 ho
// - Number composite ho
// Digit checking ke liye har digit ko baaki digits se compare karna hai.
#include <iostream>
using namespace std;

int main() {
    int password;
    cin >> password;

    int hasThree = 0;

    // Har possible digit 0 se 9 check karo
    for (int target = 0; target <= 9; target++) {

        int temp = password;
        int count = 0;

        while (temp > 0) {
            int digit = temp % 10;

            if (digit == target)
                count++;

            temp = temp / 10;
        }

        if (count == 3)
            hasThree = 1;
    }

    int divisors = 0;

    for (int d = 1; d <= password; d++) {
        if (password % d == 0)
            divisors++;
    }

    if (hasThree == 1 && divisors > 2)
        cout << "REJECTED";
    else
        cout << "ACCEPTED";

    return 0;
}