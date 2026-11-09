// 67. Cyber Access Number
// Problem
// Access number valid hoga agar:
// - Har digit ka frequency maximum 2 ho
// - Even digits ka product > odd digits ka sum
// - Number palindrome na ho
#include <iostream>
using namespace std;

int main() {
    int code;
    cin >> code;

    int invalid = 0;

    // Frequency check for every digit
    for (int target = 0; target <= 9; target++) {

        int temp = code;
        int count = 0;

        while (temp > 0) {
            if (temp % 10 == target)
                count++;

            temp = temp / 10;
        }

        if (count > 2)
            invalid = 1;
    }

    int temp = code;
    int evenProduct = 1;
    int evenFound = 0;
    int oddSum = 0;
    int reverse = 0;

    while (temp > 0) {
        int digit = temp % 10;

        if (digit % 2 == 0) {
            evenProduct = evenProduct * digit;
            evenFound = 1;
        } else {
            oddSum = oddSum + digit;
        }

        reverse = reverse * 10 + digit;

        temp = temp / 10;
    }

    if (invalid == 0) {
        if (evenFound == 1) {
            if (evenProduct > oddSum) {
                if (reverse != code)
                    cout << "ACCESS GRANTED";
                else
                    cout << "ACCESS DENIED";
            } else {
                cout << "ACCESS DENIED";
            }
        } else {
            cout << "ACCESS DENIED";
        }
    } else {
        cout << "ACCESS DENIED";
    }

    return 0;
}