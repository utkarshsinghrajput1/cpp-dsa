// 20. Solar Panel Energy Production
// Problem: N solar panels ke daily energy production input lo. Har panel ka output 5 units se kam hai toh maintenance alert do. Total energy production aur average output calculate karo.
#include <iostream>
using namespace std;

int main() {
    int N;
    double energy, total = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> energy;
        total = total + energy;

        if (energy < 5)
            cout << "Panel " << i << ": MAINTENANCE" << endl;
        else
            cout << "Panel " << i << ": NORMAL" << endl;
    }

    cout << "Total Energy: " << total << endl;

    if (N > 0)
        cout << "Average: " << total / N;

    return 0;
}