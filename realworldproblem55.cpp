// 55. E-Commerce Order ID Challenge
// Problem
// Order ID special hoga agar:
// - ID ke divisors mein se kitne divisors even hain, count karo
// - Even divisors count = odd digit count
// - Number palindrome na ho
#include <iostream>
using namespace std;

int main() {
    int id;
    cin >> id;

    int evenDivisors = 0;

    for (int d = 1; d <= id; d++) {
        if (id % d == 0) {
            if (d % 2 == 0)
                evenDivisors++;
        }
    }

    int temp = id;
    int oddDigits = 0;
    int reverse = 0;

    while (temp > 0) {
        int digit = temp % 10;

        if (digit % 2 != 0)
            oddDigits++;

        reverse = reverse * 10 + digit;

        temp = temp / 10;
    }

    if (evenDivisors == oddDigits) {
        if (id != reverse)
            cout << "SPECIAL ORDER";
        else
            cout << "NORMAL ORDER";
    } else {
        cout << "NORMAL ORDER";
    }

    return 0;
}