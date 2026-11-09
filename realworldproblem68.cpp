// 68. Cricket Score Challenge 🏏
// Problem
// L se R tak scores special honge agar:
// - Score ke divisors ki count = digit sum
// - Score ka reverse odd ho
// - Score composite ho
#include <iostream>
using namespace std;

int main() {
    int L, R;
    cin >> L >> R;

    for (int score = L; score <= R; score++) {

        int temp = score;
        int sum = 0;
        int reverse = 0;

        while (temp > 0) {
            int digit = temp % 10;

            sum = sum + digit;
            reverse = reverse * 10 + digit;

            temp = temp / 10;
        }

        int divisors = 0;

        for (int d = 1; d <= score; d++) {
            if (score % d == 0)
                divisors++;
        }

        if (divisors == sum) {
            if (reverse % 2 != 0) {
                if (divisors > 2)
                    cout << score << " ";
            }
        }
    }

    return 0;
}