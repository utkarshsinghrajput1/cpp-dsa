// 30. Public Library Fine Calculator
// Problem: N books return hui hain. Har book ke late days input lo. First 5 days ₹2/day, next 5 days ₹5/day, uske baad ₹10/day fine hai. Total fine calculate karo.
#include <iostream>
using namespace std;

int main() {
    int N, days;
    int fine, total = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> days;

        if (days <= 0)
            fine = 0;
        else if (days <= 5)
            fine = days * 2;
        else if (days <= 10)
            fine = 10 + (days - 5) * 5;
        else
            fine = 10 + 25 + (days - 10) * 10;

        total = total + fine;
        cout << "Book " << i << " Fine: " << fine << endl;
    }

    cout << "Total Fine: " << total;
    return 0;
}