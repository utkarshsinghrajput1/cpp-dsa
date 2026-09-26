// 2. Print N to 1
// Problem Statement:
// User se N input lo aur N se 1 tak reverse order mein numbers print karo.

// Example:
// Input: 5
// Output: 5 4 3 2 1

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n >= 1) {
        cout << n << " ";
        n--;
    }

    return 0;
}
