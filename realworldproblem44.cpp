// 44. ATM Transaction Validator
// Problem
// N transaction amounts diye jayenge.

// Transaction valid hoga agar:
// - Digit sum even ho
// - Amount ke divisors ki count odd ho
// - Amount palindrome na ho
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int valid = 0;

    for (int i = 1; i <= N; i++) {
        int amount;
        cin >> amount;

        int temp = amount;
        int sum = 0;
        int reverse = 0;

        while (temp > 0) {
            int digit = temp % 10;

            sum = sum + digit;
            reverse = reverse * 10 + digit;

            temp = temp / 10;
        }

        int divisorCount = 0;

        for (int d = 1; d <= amount; d++) {
            if (amount % d == 0)
                divisorCount++;
        }

        if (sum % 2 == 0) {
            if (divisorCount % 2 != 0) {
                if (amount != reverse)
                    valid++;
            }
        }
    }

    cout << "Valid Transactions: " << valid;

    return 0;
}