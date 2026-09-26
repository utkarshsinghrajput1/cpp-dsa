// 3. Print Even Numbers
// Problem Statement:
// User se N input lo aur 1 se N ke beech ke saare even numbers print karo.

// Example:
// Input: 10
// Output: 2 4 6 8 10
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int i = 1;

    while (i <= n) {
        if (i % 2 == 0) {
            cout << i << " ";
        }
        i++;
    }

    return 0;
}
