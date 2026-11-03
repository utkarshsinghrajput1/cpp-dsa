// 47. Warehouse Package Challenge
// Problem
// Package weight qualify karega agar:
// - Weight ke proper divisors ka sum > weight
// - Digit sum odd ho
// - Exactly 2 even digits hon
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int qualified = 0;

    for (int i = 1; i <= N; i++) {
        int weight;
        cin >> weight;

        int properSum = 0;

        for (int d = 1; d < weight; d++) {
            if (weight % d == 0)
                properSum = properSum + d;
        }

        int temp = weight;
        int digitSum = 0;
        int evenCount = 0;

        while (temp > 0) {
            int digit = temp % 10;

            digitSum = digitSum + digit;

            if (digit % 2 == 0)
                evenCount++;

            temp = temp / 10;
        }

        if (properSum > weight) {
            if (digitSum % 2 != 0) {
                if (evenCount == 2)
                    qualified++;
            }
        }
    }

    cout << "Qualified Packages: " << qualified;

    return 0;
}