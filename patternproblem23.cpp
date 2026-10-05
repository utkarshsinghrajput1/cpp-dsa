// 23. Pascal's Triangle
// For n = 5:
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {

        for (int space = 0; space < n - i - 1; space++)
            cout << " ";

        int value = 1;

        for (int j = 0; j <= i; j++) {

            cout << value << " ";

            value = value * (i - j) / (j + 1);
        }

        cout << endl;
    }

    return 0;
}