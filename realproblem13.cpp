// 13. Airline Baggage Charge System
// Problem: N passengers ka baggage weight input lo. 15 kg tak free hai. 15 kg se zyada har kilogram par ₹200 charge karo. Total baggage revenue calculate karo.
#include <iostream>
using namespace std;

int main() {
    int N;
    double weight, charge, total = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> weight;

        if (weight <= 15)
            charge = 0;
        else
            charge = (weight - 15) * 200;

        total = total + charge;
        cout << "Passenger " << i << ": " << charge << endl;
    }

    cout << "Total Revenue: " << total;
    return 0;
}