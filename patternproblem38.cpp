// 38. Diagonal Alphabet Matrix
// Question
// n × n matrix me alphabet ko diagonal distance ke according print karo.
// For n = 5:
// A B C D E
// B C D E F
// C D E F G
// D E F G H
// E F G H I
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            char ch = 'A' + i + j;

            cout << ch << " ";
        }

        cout << endl;
    }

    return 0;
}