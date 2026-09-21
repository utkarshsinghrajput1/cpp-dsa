// Q18. Electricity Meter
// The previous electricity meter reading is 1200 units. 
// Write a C++ program using a while loop to continuously accept new meter readings. 
// Stop when the user enters -1. 
// For every valid reading, calculate the units consumed since the previous reading and maintain the total consumption.
// Logic:
// START
//   ↓
// Initialize:
// previousReading = 1200
// totalConsumption = 0
//   ↓
// Input New Meter Reading
//   ↓
// Is reading = -1?
//   ├── YES → Print Total Consumption → STOP
//   │
//   └── NO
//        ↓
// Calculate:
// unitsConsumed = newReading - previousReading
//        ↓
// Print Units Consumed
//        ↓
// totalConsumption =
// totalConsumption + unitsConsumed
//        ↓
// previousReading = newReading
//        ↓
// Input New Meter Reading Again
//        ↓
// Go back to:
// Is reading = -1?

// Yaad rakhne ka pattern:
// INPUT
//  ↓
// CHECK -1
//  ↓
// CALCULATE CONSUMPTION
//  ↓
// ADD TO TOTAL
//  ↓
// UPDATE PREVIOUS READING
//  ↓
// INPUT AGAIN
//  ↓
// REPEAT
// Solution:
#include <iostream>
using namespace std;

int main()
{
    int previousReading = 1200;   // [INITIALIZE] Previous meter reading
    int newReading;               // [INPUT] New meter reading
    int totalConsumption = 0;     // [ACCUMULATOR] Total units consumed

    cout << "Enter new meter reading (-1 to stop): ";
    cin >> newReading;            // [INPUT] Reading lena

    while (newReading != -1)      // [CONDITION] -1 tak loop chalega
    {
        int unitsConsumed = newReading - previousReading;
        // [WORK] Current reading - previous reading

        cout << "Units consumed = " << unitsConsumed << endl;

        totalConsumption = totalConsumption + unitsConsumed;
        // [UPDATE] Total consumption me units add karo

        previousReading = newReading;
        // [UPDATE] Current reading ko previous bana do

        cout << "Enter new meter reading (-1 to stop): ";
        cin >> newReading;        // [INPUT] Next reading
    }

    cout << "\nTotal Consumption = "
         << totalConsumption << " units" << endl;
    // [OUTPUT] Final total consumption

    return 0;
}