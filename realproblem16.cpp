// 16. Traffic Toll Collection System
// Problem: Vehicles ke types input lo: 1 car, 2 bus, 3 truck. Car toll ₹50, bus ₹100, truck ₹150. Invalid vehicle type reject karo. Total toll collection print karo.
#include <iostream>
using namespace std;

int main() {
    int N, type;
    int total = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> type;

        if (type == 1)
            total = total + 50;
        else if (type == 2)
            total = total + 100;
        else if (type == 3)
            total = total + 150;
        else
            cout << "Invalid Vehicle" << endl;
    }

    cout << "Total Toll: " << total;
    return 0;
}