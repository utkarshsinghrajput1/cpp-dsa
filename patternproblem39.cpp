// 39. The Alternating Sum Triangle ➕➖
// Question: Har row mein numbers print karo, lekin odd positions positive aur even positions negative hongi.
// For n = 5:
// 1
// 1 -2
// 1 -2 3
// 1 -2 3 -4
// 1 -2 3 -4 5
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= i; j++) {

            if (j % 2 == 0)
                cout << -j << " ";
            else
                cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}