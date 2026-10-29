// Problem 31: Factory Conveyor Belt Jam Recovery
// Question: Factory mein 3 conveyor belts hain. Har belt ki maximum capacity 10 packages hai. Har round mein packages add hote hain. Agar belt jam threshold 8 cross kare, toh packages ko doosri belts par transfer karne ki koshish karo.

#include <iostream>
using namespace std;

int main() {
    int belt1 = 7, belt2 = 5, belt3 = 4;
    int capacity = 10;
    int jamAlerts = 0;

    for (int round = 1; round <= 4; round++) {
        int add1, add2, add3;

        cout << "Enter new packages for belts 1, 2, 3: ";
        cin >> add1 >> add2 >> add3;

        // Reject negative package arrivals
        if (add1 < 0 || add2 < 0 || add3 < 0) {
            cout << "Invalid arrival values. Round skipped.\n";
            continue;
        }

        // Add packages only if the belt has enough capacity
        if (belt1 + add1 <= capacity) belt1 += add1;
        else cout << "Belt 1 arrival rejected\n";

        if (belt2 + add2 <= capacity) belt2 += add2;
        else cout << "Belt 2 arrival rejected\n";

        if (belt3 + add3 <= capacity) belt3 += add3;
        else cout << "Belt 3 arrival rejected\n";

        // A jam is suspected when a belt holds more than 8 packages
        if (belt1 > 8) {
            jamAlerts++;

            // Transfer one package if Belt 2 has space
            if (belt2 < capacity) {
                belt1--;
                belt2++;
            }
            else if (belt3 < capacity) {
                belt1--;
                belt3++;
            }
        }

        if (belt2 > 8) {
            jamAlerts++;

            if (belt1 < capacity) {
                belt2--;
                belt1++;
            }
            else if (belt3 < capacity) {
                belt2--;
                belt3++;
            }
        }

        if (belt3 > 8) {
            jamAlerts++;

            if (belt1 < capacity) {
                belt3--;
                belt1++;
            }
            else if (belt2 < capacity) {
                belt3--;
                belt2++;
            }
        }

        cout << "Round " << round << ": "
             << belt1 << ", " << belt2 << ", " << belt3 << "\n";
    }

    cout << "\nFinal package counts:\n";
    cout << "Belt 1: " << belt1 << "\n";
    cout << "Belt 2: " << belt2 << "\n";
    cout << "Belt 3: " << belt3 << "\n";
    cout << "Jam warnings: " << jamAlerts << "\n";

    return 0;
}

// Important logic:
// - continue invalid input wale round ko skip karta hai.
// - Capacity check ke baad hi packages add hote hain.
// - Jam warning par ek package alternate belt mein transfer hota hai.
// - Jam warning count events ko track karta hai, unique jams ko nahi.
