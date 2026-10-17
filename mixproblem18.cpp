// Question 18: Numerical Spiral Without Arrays
// N input lo aur N × N numbers ka clockwise spiral print karo, bina arrays ke.
// N = 4 ke liye target output:
// 1   2   3   4
// 12  13  14  5
// 11  16  15  6
// 10  9   8   7
// Hard restriction: array, vector, string aur 2D matrix allowed nahi. Sirf loops, conditions aur arithmetic.
// Concept: nested loops, boundaries, coordinate logic, arithmetic.

// Task: Clockwise spiral mein N × N numbers print karo, bina arrays ke.
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N <= 0) {
        cout << "INVALID";
        return 0;
    }

    // Har cell (i, j) ke liye calculate karo
    // ki woh kis spiral layer mein hai.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            int top = i;
            int left = j;
            int bottom = N - 1 - i;
            int right = N - 1 - j;

            int layer = top;

            if (left < layer)
                layer = left;
            if (bottom < layer)
                layer = bottom;
            if (right < layer)
                layer = right;

            int size = N - 2 * layer;
            int r = i - layer;
            int c = j - layer;

            int value;
            int offset = 0;

            // Current layer ke top-left se number ka offset
            if (r == 0) {
                offset = c;
            } else if (c == size - 1) {
                offset = (size - 1) + r;
            } else if (r == size - 1) {
                offset = 2 * (size - 1)
                       + (size - 1 - c);
            } else {
                offset = 3 * (size - 1)
                       + (size - 1 - r);
            }

            // Outer layers mein pehle jitne numbers hain
            // unka total: N*N - size*size
            value = N * N - size * size + offset + 1;

            cout << value << "\t";
        }

        cout << "\n";
    }

    return 0;
}

// Logic: Har cell ke liye uski outer boundary se distance nikalo. Phir decide karo ki cell top, right, bottom ya left side par hai aur uska number calculate karo.
