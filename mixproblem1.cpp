// Problem 1: Number Pattern with Conditions
// Question: User se n input lo aur aisa pattern print karo jahan har row mein 1 se lekar row number tak numbers hon. Even numbers ko E aur odd numbers ko O se represent karo.
// Example (n = 5):
// O
// O E
// O E O
// O E O E
// O E O E O

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j % 2 == 0) {
                cout << "E ";
            } else {
                cout << "O ";
            }
        }

        cout << endl;
    }

    return 0;
}
// Logic samajh: Outer loop rows control karta hai aur inner loop har row mein elements print karta hai. if-else decide karta hai ki E print hoga ya O.
