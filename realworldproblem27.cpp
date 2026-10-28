// Problem 27: Cold-Storage Temperature Recovery
// Question: 3 storage chambers ki temperatures 12°C, 9°C aur 15°C hain. Har round mein active cooling temperature ko 2°C kam karti hai. Safe maximum 8°C hai. Har chamber ko safe temperature tak laane ki koshish karo, lekin temperature -2°C se neeche nahi jaana chahiye.

#include <iostream>
using namespace std;

int main() {
    int temp1 = 12;
    int temp2 = 9;
    int temp3 = 15;

    int safeMax = 8;
    int safeMin = -2;
    int rounds = 0;

    while (temp1 > safeMax ||
           temp2 > safeMax ||
           temp3 > safeMax) {

        // Cool each chamber that is above the safe maximum
        if (temp1 > safeMax) temp1 -= 2;
        if (temp2 > safeMax) temp2 -= 2;
        if (temp3 > safeMax) temp3 -= 2;

        // Enforce the minimum temperature limit
        if (temp1 < safeMin) temp1 = safeMin;
        if (temp2 < safeMin) temp2 = safeMin;
        if (temp3 < safeMin) temp3 = safeMin;

        rounds++;

        cout << "Round " << rounds << ": "
             << temp1 << " C, "
             << temp2 << " C, "
             << temp3 << " C\n";
    }

    cout << "\nAll chambers are in the target range.\n";
    cout << "Total rounds: " << rounds << "\n";

    return 0;
}


// Important logic:
// - while tab tak chalta hai jab tak koi chamber safe maximum se upar hai.
// - Har round mein sirf warm chambers cool hote hain.
// - Temperature lower limit se neeche nahi ja sakti.
// - Real cold storage mein sensor errors, cooling delays aur food-specific safe ranges bhi consider karne padte hain.
