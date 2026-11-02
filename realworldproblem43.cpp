// 43. Building Security Gate
// Problem
// N employees ke security codes diye jayenge.

// Employee allowed hoga agar:
// - Digit sum 5 se divisible ho
// - Code mein even digits ki count odd ho
// - Code prime na ho
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int allowed = 0;

    for (int i = 1; i <= N; i++) {
        int code;
        cin >> code;

        int temp = code;
        int sum = 0;
        int evenCount = 0;

        while (temp > 0) {
            int digit = temp % 10;

            sum = sum + digit;

            if (digit % 2 == 0)
                evenCount++;

            temp = temp / 10;
        }

        int divisorCount = 0;

        for (int d = 1; d <= code; d++) {
            if (code % d == 0)
                divisorCount++;
        }

        if (sum % 5 == 0) {
            if (evenCount % 2 != 0) {
                if (divisorCount != 2)
                    allowed++;
            }
        }
    }

    cout << "Allowed Employees: " << allowed;

    return 0;
}