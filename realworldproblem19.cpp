// Problem 19: Solar-Powered Streetlight Controller
// Question: 3 streetlight zones ki batteries limited hain. Har round mein battery 3 units consume karti hai aur 2 units solar charge milta hai. Critical zone ko minimum battery reserve maintain karna hai. Battery capacity exceed nahi honi chahiye.

#include <iostream>
using namespace std;

int main() {
    int battery1 = 10;
    int battery2 = 7;
    int battery3 = 5;

    int capacity = 12;
    int rounds = 5;

    for (int i = 1; i <= rounds; i++) {
        // Apply solar charging, without exceeding battery capacity
        if (battery1 + 2 <= capacity) battery1 += 2;
        else battery1 = capacity;

        if (battery2 + 2 <= capacity) battery2 += 2;
        else battery2 = capacity;

        if (battery3 + 2 <= capacity) battery3 += 2;
        else battery3 = capacity;

        // Critical energy consumption: Zone 1
        if (battery1 >= 3) battery1 -= 3;
        else battery1 = 0;

        // Non-critical zones can be turned off when energy is insufficient
        if (battery2 >= 3) battery2 -= 3;
        else battery2 = 0;

        if (battery3 >= 3) battery3 -= 3;
        else battery3 = 0;

        cout << "Round " << i << ": "
             << battery1 << ", "
             << battery2 << ", "
             << battery3 << "\n";
    }

    cout << "\nFinal battery levels:\n";
    cout << "Zone 1: " << battery1 << "\n";
    cout << "Zone 2: " << battery2 << "\n";
    cout << "Zone 3: " << battery3 << "\n";

    return 0;
}

// Important logic:
// - Charging aur consumption har round mein apply hote hain.
// - if capacity se zyada charging ko rokta hai.
// - Battery zero se neeche nahi jaati.
// - Is version mein critical priority sirf zone labeling hai; sabhi zones ko equal consumption diya gaya hai.
