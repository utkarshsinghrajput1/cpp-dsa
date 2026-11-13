// 11. Delivery Fleet Fuel Consumption
// Problem: N delivery vehicles ka distance aur fuel consumed input lo. Har vehicle ki mileage calculate karo. 10 km/litre se kam mileage wale vehicles ko inefficient mark karo.
#include <iostream>
using namespace std;

int main() {
    int N;
    double distance, fuel;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> distance >> fuel;

        if (fuel <= 0) {
            cout << "Invalid fuel" << endl;
        } else {
            double mileage = distance / fuel;
            cout << "Vehicle " << i << ": " << mileage << endl;

            if (mileage < 10)
                cout << "INEFFICIENT" << endl;
            else
                cout << "EFFICIENT" << endl;
        }
    }

    return 0;
}