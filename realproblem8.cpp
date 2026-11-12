// 8. Electricity Bill Slab Calculator
// Problem: Electricity consumption units ke according bill calculate karo:
// - First 100 units: ₹2 per unit
// - Next 100 units: ₹3 per unit
// - Above 200 units: ₹5 per unit
#include <iostream>
using namespace std;

int main() {
    int units;
    double bill = 0;
    cin >> units;

    if (units <= 100)
        bill = units * 2;
    else if (units <= 200)
        bill = 100 * 2 + (units - 100) * 3;
    else
        bill = 100 * 2 + 100 * 3 + (units - 200) * 5;

    cout << "Electricity Bill: " << bill;
    return 0;
}
