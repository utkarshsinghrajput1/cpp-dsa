// 48.Row-Wise Cumulative Sum
// Level: Very Hard
// Case: Har row mein numbers 1 se start honge, aur har agla number pichhle numbers ka cumulative sum hoga.
// Example: n = 5
// 1
// 1 3
// 1 3 6
// 1 3 6 10
// 1 3 6 10 15
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int sum = 0;

        for (int j = 1; j <= i; j++) {
            sum += j;
            cout << sum << " ";
        }

        cout << '\n';
    }

    return 0;
}
// Logic: Running sum maintain karna hai; har row mein sum zero se restart hota hai.
