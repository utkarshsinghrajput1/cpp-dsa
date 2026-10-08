// 37. Checkerboard Number Pattern
// Question
// n × n grid banao jisme adjacent cells alternate 1 aur 0 hon.
// For n = 6:
// 1 0 1 0 1 0
// 0 1 0 1 0 1
// 1 0 1 0 1 0
// 0 1 0 1 0 1
// 1 0 1 0 1 0
// 0 1 0 1 0 1

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if ((i + j) % 2 == 0)
                cout << "1 ";
            else
                cout << "0 ";
        }

        cout << endl;
    }

    return 0;
}