// 39. Wind Turbine Energy Output
// Problem: N wind turbines ki rotational speed aur energy output input lo. Minimum speed 10 units hai. Isse kam speed par turbine inactive hai. Active turbines ki total energy calculate karo.
#include <iostream>
using namespace std;

int main() {
    int N;
    double speed, energy, total = 0;
    int active = 0;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> speed >> energy;

        if (speed < 10) {
            cout << "Turbine " << i << ": INACTIVE" << endl;
        } else {
            active++;
            total = total + energy;
            cout << "Turbine " << i << ": ACTIVE" << endl;
        }
    }

    cout << "Active Turbines: " << active << endl;
    cout << "Total Energy: " << total;

    return 0;
}