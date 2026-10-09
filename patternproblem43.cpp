// 43.DNA Sequence Symmetry
// Level: Hard
// Case: DNA research mein ek symbolic sequence print karni hai. Har row mein alphabet sequence aage jaayegi aur phir reverse hogi.
// Example: n = 5
// A
// ABA
// ABCBA
// ABCDCBA
// ABCDEDCBA
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {

        for (int j = 0; j < i; j++)
            cout << char('A' + j);

        for (int j = i - 2; j >= 0; j--)
            cout << char('A' + j);

        cout << '\n';
    }

    return 0;
}