// LEVEL 2 — Space + Star Patterns
// 5. Right-Aligned Triangle
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}

// Yaad rakh:
// Har row:
// spaces + stars

// For row i:
// spaces = n - i
// stars = i