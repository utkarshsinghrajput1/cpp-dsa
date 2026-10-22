// Question 4 — Electric Vehicle Charging Station
// Problem statement
// Three electric vehicles share a station with two charging slots. Each vehicle has a current battery level, a target level and a charging rate.

// For this simplified model:
// - Each vehicle's charging rate is also its power consumption per minute.
// - The station can supply a maximum total power per minute.
// - At most two vehicles can charge at once.
// - When choosing vehicles, prioritize the lowest battery percentage.
// - If battery levels tie, prioritize the lower vehicle number.
// - A vehicle stops charging when it reaches its target.

#include <iostream>
using namespace std;

int main() {
    int b1, b2, b3;
    int t1, t2, t3;
    int r1, r2, r3;
    int powerLimit, maxMinutes;

    cout << "Enter starting battery levels: ";
    cin >> b1 >> b2 >> b3;

    cout << "Enter target battery levels: ";
    cin >> t1 >> t2 >> t3;

    cout << "Enter charging rates: ";
    cin >> r1 >> r2 >> r3;

    cout << "Enter station power limit and time limit: ";
    cin >> powerLimit >> maxMinutes;

    if (b1 < 0 || b1 > 100 || b2 < 0 || b2 > 100 ||
        b3 < 0 || b3 > 100 ||
        t1 < b1 || t1 > 100 ||
        t2 < b2 || t2 > 100 ||
        t3 < b3 || t3 > 100 ||
        r1 <= 0 || r2 <= 0 || r3 <= 0 ||
        powerLimit <= 0 || maxMinutes < 0) {
        cout << "Invalid input.\n";
        return 0;
    }

    int minute = 1;
    int energy = 0;

    while (minute <= maxMinutes &&
           (b1 < t1 || b2 < t2 || b3 < t3)) {

        int slot1 = 0, slot2 = 0;
        int usedPower = 0;

        // Choose the first vehicle with the lowest
        // battery percentage that still needs charging.
        int selected = 0;
        int lowest = 101;

        if (b1 < t1 && b1 < lowest) {
            lowest = b1;
            selected = 1;
        }

        if (b2 < t2 && b2 < lowest) {
            lowest = b2;
            selected = 2;
        }

        if (b3 < t3 && b3 < lowest) {
            lowest = b3;
            selected = 3;
        }

        // Assign the first slot if power permits.
        if (selected == 1 && r1 <= powerLimit) {
            slot1 = 1;
            usedPower += r1;
        }
        else if (selected == 2 && r2 <= powerLimit) {
            slot1 = 2;
            usedPower += r2;
        }
        else if (selected == 3 && r3 <= powerLimit) {
            slot1 = 3;
            usedPower += r3;
        }

        // Choose a second vehicle, excluding slot 1.
        selected = 0;
        lowest = 101;

        if (slot1 != 1 && b1 < t1 &&
            r1 <= powerLimit - usedPower && b1 < lowest) {
            lowest = b1;
            selected = 1;
        }

        if (slot1 != 2 && b2 < t2 &&
            r2 <= powerLimit - usedPower && b2 < lowest) {
            lowest = b2;
            selected = 2;
        }

        if (slot1 != 3 && b3 < t3 &&
            r3 <= powerLimit - usedPower && b3 < lowest) {
            lowest = b3;
            selected = 3;
        }

        if (selected == 1) {
            slot2 = 1;
            usedPower += r1;
        }
        else if (selected == 2) {
            slot2 = 2;
            usedPower += r2;
        }
        else if (selected == 3) {
            slot2 = 3;
            usedPower += r3;
        }

        // Charge the selected vehicles.
        // Battery percentage cannot exceed the target.
        if (slot1 == 1) {
            if (b1 + r1 > t1) b1 = t1;
            else b1 += r1;
        }
        else if (slot1 == 2) {
            if (b2 + r2 > t2) b2 = t2;
            else b2 += r2;
        }
        else if (slot1 == 3) {
            if (b3 + r3 > t3) b3 = t3;
            else b3 += r3;
        }

        if (slot2 == 1) {
            if (b1 + r1 > t1) b1 = t1;
            else b1 += r1;
        }
        else if (slot2 == 2) {
            if (b2 + r2 > t2) b2 = t2;
            else b2 += r2;
        }
        else if (slot2 == 3) {
            if (b3 + r3 > t3) b3 = t3;
            else b3 += r3;
        }

        // Used power is the energy consumed this minute.
        energy += usedPower;

        cout << "\nMinute " << minute
             << " | Batteries: " << b1 << "%, "
             << b2 << "%, " << b3 << "%"
             << " | Power: " << usedPower;

        minute++;
    }

    cout << "\n\nFinal batteries: "
         << b1 << "%, " << b2 << "%, " << b3 << "%";

    cout << "\nTotal energy units: " << energy;

    if (b1 >= t1 && b2 >= t2 && b3 >= t3)
        cout << "\nAll vehicles fully charged to their targets.\n";
    else
        cout << "\nTime limit reached; some vehicles are unfinished.\n";

    return 0;
}

// Important logic
// - The first selection finds the lowest battery among eligible vehicles.
// - The second selection excludes the vehicle already occupying slot 1.
// - powerLimit - usedPower calculates the remaining available power.
// - energy records the power used in each simulated minute.
// This simplified model assumes each charging rate is an integer number of battery percentage points per minute and a matching integer power unit.
