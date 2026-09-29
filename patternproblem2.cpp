// 2. Solid Rectangle
// Question: rows aur columns input lekar rectangle print karo.
// For rows = 4, columns = 6:
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
