// Print even numbers from 1 to N 
// Solution:
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int i = 2;

    while (i <= n) {
        cout << i << " ";
        i += 2;
    }

    return 0;
}