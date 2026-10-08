// 1.Spiral Matrix Pattern
// Question: n × n matrix ko spiral order me 1 se n² tak fill karo.
// For n = 5
//  1  2  3  4  5
// 16 17 18 19  6
// 15 24 25 20  7
// 14 23 22 21  8
// 13 12 11 10  9
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[100][100];

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;

    int num = 1;

    while (top <= bottom && left <= right) {

        // Left -> Right
        for (int j = left; j <= right; j++)
            a[top][j] = num++;

        top++;

        // Top -> Bottom
        for (int i = top; i <= bottom; i++)
            a[i][right] = num++;

        right--;

        // Right -> Left
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                a[bottom][j] = num++;

            bottom--;
        }

        // Bottom -> Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                a[i][left] = num++;

            left++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";

        cout << endl;
    }

    return 0;
}