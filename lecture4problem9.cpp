// Q. Count digits problem
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    int count = 0;

    while (n > 0) {
        n = n / 10;
        count++;
    }

    cout << "Number of digits = " << count;

    return 0;
}