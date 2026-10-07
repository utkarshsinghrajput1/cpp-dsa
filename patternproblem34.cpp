// 34. Concentric Number Square
// For n = 4:
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int size = 2 * n - 1;

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            int top = i;
            int left = j;
            int right = size - 1 - j;
            int bottom = size - 1 - i;

            int layer = min(min(top, bottom), min(left, right));

            cout << n - layer;
        }

        cout << endl;
    }

    return 0;
}