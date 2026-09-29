// Solid Square
// Question: n rows aur n columns ka star square print karo.
// For n = 5:
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}