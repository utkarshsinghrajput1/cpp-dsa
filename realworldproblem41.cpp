// 41. Factory Quality Inspector
// Problem
// Ek factory N products inspect karti hai. Har product ka ID number diya jayega.

// Product PASS hoga agar:
// - ID ke even digits ka sum > odd digits ka sum
// - ID ke total divisors even hon
// - ID composite ho
// Total passed products print karo.
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int passed = 0;

    for (int i = 1; i <= N; i++) {
        int id;
        cin >> id;

        int temp = id;
        int evenSum = 0;
        int oddSum = 0;

        // Check every digit
        while (temp > 0) {
            int digit = temp % 10;

            if (digit % 2 == 0)
                evenSum = evenSum + digit;
            else
                oddSum = oddSum + digit;

            temp = temp / 10;
        }

        int divisorCount = 0;

        // Count divisors
        for (int d = 1; d <= id; d++) {
            if (id % d == 0)
                divisorCount++;
        }

        // Composite + conditions
        if (divisorCount > 2 && divisorCount % 2 == 0) {
            if (evenSum > oddSum)
                passed++;
        }
    }

    cout << "Passed Products: " << passed;

    return 0;
}