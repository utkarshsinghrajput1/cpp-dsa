// 46. Parking Ticket Detector
// Problem
// Har car ka number code diya jayega.

// Ticket tab milega agar:
// - Odd digits ka sum > even digits ka sum
// - Digit sum prime ho
// - Number 3 se divisible ho
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int tickets = 0;

    for (int i = 1; i <= N; i++) {
        int number;
        cin >> number;

        int temp = number;
        int oddSum = 0;
        int evenSum = 0;
        int digitSum = 0;

        while (temp > 0) {
            int digit = temp % 10;

            digitSum = digitSum + digit;

            if (digit % 2 == 0)
                evenSum = evenSum + digit;
            else
                oddSum = oddSum + digit;

            temp = temp / 10;
        }

        int divisorCount = 0;

        for (int d = 1; d <= digitSum; d++) {
            if (digitSum % d == 0)
                divisorCount++;
        }

        if (number % 3 == 0) {
            if (oddSum > evenSum) {
                if (divisorCount == 2)
                    tickets++;
            }
        }
    }

    cout << "Tickets: " << tickets;

    return 0;
}