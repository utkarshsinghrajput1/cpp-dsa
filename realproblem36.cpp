// 36. Battery Charging Station
// Problem: Ek battery ka initial charge percentage aur charging rate per minute input lo. Har minute charge increase karo. 100% hone par charging stop karo aur total minutes print karo.
#include <iostream>
using namespace std;

int main() {
    int charge, rate, minutes = 0;
    cin >> charge >> rate;

    if (charge < 0 || charge > 100 || rate <= 0) {
        cout << "Invalid Input";
    } else {
        while (charge < 100) {
            charge = charge + rate;
            minutes++;

            if (charge > 100)
                charge = 100;
        }

        cout << "Fully Charged" << endl;
        cout << "Time Required: " << minutes << " minutes";
    }

    return 0;
}