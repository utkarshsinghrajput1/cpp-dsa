// 12. Taxi Fare Calculator
// Problem: Taxi ka base fare ₹50 hai. First 5 km free included hain. Uske baad first additional 10 km ke ₹12/km aur uske baad ₹15/km charge karo.
#include <iostream>
using namespace std;

int main() {
    double km, fare = 50;
    cin >> km;

    if (km > 5 && km <= 15)
        fare = fare + (km - 5) * 12;
    else if (km > 15)
        fare = fare + 10 * 12 + (km - 15) * 15;

    cout << "Taxi Fare: " << fare;
    return 0;
}