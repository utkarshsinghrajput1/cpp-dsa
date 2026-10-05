// 27. Butterfly Pattern
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Upper half
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= i; j++)
            cout << "*";

        for (int j = 1; j <= 2 * (n - i); j++)
            cout << " ";

        for (int j = 1; j <= i; j++)
            cout << "*";

        cout << endl;
    }

    // Lower half
    for (int i = n - 1; i >= 1; i--) {

        for (int j = 1; j <= i; j++)
            cout << "*";

        for (int j = 1; j <= 2 * (n - i); j++)
            cout << " ";

        for (int j = 1; j <= i; j++)
            cout << "*";

        cout << endl;
    }

    return 0;
}