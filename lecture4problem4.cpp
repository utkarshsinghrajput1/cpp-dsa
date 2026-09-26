// 4. Sum of 1 to N
// Problem Statement:
// User se N input lo aur 1 + 2 + 3 + ... + N ka sum calculate karo.

// Example:
// Input: 5
// Output: 15
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int i = 1;
    int sum = 0;

    while (i <= n) {
        sum = sum + i;
        i++;
    }

    cout << sum;

    return 0;
}
