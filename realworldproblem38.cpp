// Problem 38: Smart Building Fire-Safety Response
// Question: 3 building zones ke smoke readings har round input lo. Agar smoke level 70 ya usse zyada ho, toh dangerous reading count karo. Kisi zone mein 2 consecutive dangerous readings aane par evacuation alert issue karo.

#include <iostream>
using namespace std;

int main() {
    int streak1 = 0, streak2 = 0, streak3 = 0;
    int alert1 = 0, alert2 = 0, alert3 = 0;

    int rounds = 4;

    for (int i = 1; i <= rounds; i++) {
        int smoke1, smoke2, smoke3;

        cout << "Enter smoke levels for 3 zones: ";
        cin >> smoke1 >> smoke2 >> smoke3;

        // Zone 1: track consecutive dangerous readings
        if (smoke1 >= 70) {
            streak1++;

            if (streak1 >= 2 && alert1 == 0) {
                alert1 = 1;
                cout << "Evacuation alert for Zone 1\n";
            }
        } else {
            streak1 = 0;
        }

        // Zone 2
        if (smoke2 >= 70) {
            streak2++;

            if (streak2 >= 2 && alert2 == 0) {
                alert2 = 1;
                cout << "Evacuation alert for Zone 2\n";
            }
        } else {
            streak2 = 0;
        }

        // Zone 3
        if (smoke3 >= 70) {
            streak3++;

            if (streak3 >= 2 && alert3 == 0) {
                alert3 = 1;
                cout << "Evacuation alert for Zone 3\n";
            }
        } else {
            streak3 = 0;
        }
    }

    cout << "\nFinal alert status:\n";
    cout << "Zone 1: " << alert1 << "\n";
    cout << "Zone 2: " << alert2 << "\n";
    cout << "Zone 3: " << alert3 << "\n";

    return 0;
}

// Important logic:
// - Dangerous reading par streak counter increase hota hai.
// - Safe reading counter reset karti hai.
// - alert flag repeated alerts ko rokta hai.
// - Yeh programming simulation hai, actual fire-safety system ka replacement nahi.
