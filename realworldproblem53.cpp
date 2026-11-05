// 53. Airport Boarding Token
// Problem
// Token valid hoga agar:
// - Exactly one digit 0
// - Digit sum prime
// - Total divisor count odd
#include <iostream> 
using namespace std;

int main() {
    int token;
    cin >> token;

    int temp = token;
    int sum = 0;
    int zeroCount = 0;

    while (temp > 0) {
        int digit = temp % 10;

        sum = sum + digit;

        if (digit == 0)
            zeroCount++;

        temp = temp / 10;
    }

    int sumDivisors = 0;

    for (int d = 1; d <= sum; d++) {
        if (sum % d == 0)
            sumDivisors++;
    }

    int divisors = 0;

    for (int d = 1; d <= token; d++) {
        if (token % d == 0)
            divisors++;
    }

    if (zeroCount == 1) {
        if (sumDivisors == 2) {
            if (divisors % 2 != 0)
                cout << "VALID";
            else
                cout << "INVALID";
        } else {
            cout << "INVALID";
        }
    } else {
        cout << "INVALID";
    }

    return 0;
}