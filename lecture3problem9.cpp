// 1. Electricity Bill Calculator

// Question: Units input lo.

// First 100 units → ₹5/unit
// Next 100 → ₹7/unit
// Above 200 → ₹10/unit

// While loop se bill calculate karo.
// Solution: Below is a C++ program that calculates the electricity bill based on the units consumed by the user.
#include <iostream>
using namespace std;

int main()
{
    int units;                    // [INPUT] Electricity units
    int bill = 0;                 // [ACCUMULATOR] Total bill

    cout << "Enter units: ";
    cin >> units;

    // [LOOP] Jab tak units remaining hain
    while (units > 0)
    {
        if (units <= 100)
        {
            bill = bill + units * 5;      // [RATE] First slab
            units = 0;                    // [STOP] All units processed
        }
        else if (units <= 200)
        {
            bill = bill + 100 * 5;        // [SLAB 1]
            units = units - 100;          // [UPDATE]
        }
        else
        {
            bill = bill + 100 * 5;        // [SLAB 1]
            bill = bill + 100 * 7;        // [SLAB 2]

            units = units - 200;          // [UPDATE]
        }
    }

    cout << "Total Bill = Rs. " << bill;

    return 0;
}