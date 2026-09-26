// 1. Print 1 to N
// Problem: User se N input lo aur 1 se N tak numbers print karo.

#include <iostream>
using namespace std;

int main() {
    int n, i = 1;
    cin >> n;

    while (i <= n) {
        cout << i << " ";
        i++;
    }

    return 0;
}
