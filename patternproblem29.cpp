// 29. X Pattern
// For n = 5:
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {

            if (j == i || j == n - i + 1)
                cout << "*";
            else
                cout << " ";
        }

        cout << endl;
    }

    return 0;
}

// Isme 2 conditions important hain:
// j == i
// and 
// j == n - i + 1