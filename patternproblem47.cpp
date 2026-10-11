// 47.Weather Risk Map
// Level: Very Hard
// Case: Har location ka risk score i² + j² hai.
// - Score 20 se zyada → H (High)
// - Score 10 se zyada, lekin 20 ya usse kam → M (Medium)
// - Otherwise → L (Low)
// Example: n = 4
// L L L M
// L L M M
// L M M H
// M M H H
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            int score = i * i + j * j;

            if (score > 20)
                cout << "H ";
            else if (score > 10)
                cout << "M ";
            else
                cout << "L ";
        }

        cout << '\n';
    }

    return 0;
}
// Logic: Conditions ko descending thresholds mein check karna hai.
