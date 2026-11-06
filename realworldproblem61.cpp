// 61. Online Exam Roll Number
// Problem
// Roll number lucky hoga agar:
// - Digit sum prime
// - Even digit count > odd digit count
// - Total divisor count divisible by 3
#include <iostream>
using namespace std;

int main() {
    int roll;
    cin >> roll;

    int temp = roll;
    int sum = 0;
    int evenCount = 0;
    int oddCount = 0;

    while (temp > 0) {
        int digit = temp % 10;

        sum = sum + digit;

        if (digit % 2 == 0)
            evenCount++;
        else
            oddCount++;

        temp = temp / 10;
    }

    int sumDivisors = 0;

    for (int d = 1; d <= sum; d++) {
        if (sum % d == 0)
            sumDivisors++;
    }

    int divisors = 0;

    for (int d = 1; d <= roll; d++) {
        if (roll % d == 0)
            divisors++;
    }

    if (sumDivisors == 2) {
        if (evenCount > oddCount) {
            if (divisors % 3 == 0)
                cout << "LUCKY";
            else
                cout << "NOT LUCKY";
        } else {
            cout << "NOT LUCKY";
        }
    } else {
        cout << "NOT LUCKY";
    }

    return 0;
}