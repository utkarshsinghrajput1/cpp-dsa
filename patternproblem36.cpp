// 36. Ultimate Alternating Row-Column Pattern
// Ye wala previous patterns se kaafi different hai.
// Question
// n × n matrix me number 1 se start karo.
// Rule:
// - Even row → numbers left to right
// - Odd row → numbers right to left
// - Lekin har row ke numbers ka sign alternate hoga.
// For n = 5:
//   1   2   3   4   5
// -10  -9  -8  -7  -6
//  11  12  13  14  15
// -20 -19 -18 -17 -16
//  21  22  23  24  25
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int num = 1;

    for (int i = 0; i < n; i++) {

        if (i % 2 == 0) {

            // Positive row
            for (int j = 0; j < n; j++) {
                cout << num << "\t";
                num++;
            }

        } else {

            // Store current row
            int start = num;

            // Negative row
            for (int j = 0; j < n; j++) {
                cout << -num << "\t";
                num++;
            }
        }

        cout << endl;
    }

    return 0;
}