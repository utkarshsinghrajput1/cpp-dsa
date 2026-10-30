// Problem 34: City Snow-Clearing Scheduler
// Question: 3 roads par snow depth 8, 5 aur 10 units hai. Har clearing round mein sabse zyada snow wali road se 3 units remove karo. Total 5 rounds tak operate karo ya snow khatam hone par stop karo.

#include <iostream>
using namespace std;

int main() {
    int snow1 = 8;
    int snow2 = 5;
    int snow3 = 10;

    int rounds = 5;
    int completedRounds = 0;

    while (completedRounds < rounds) {
        // Stop if every road is clear
        if (snow1 == 0 && snow2 == 0 && snow3 == 0) {
            break;
        }

        // Clear the road with the deepest snow
        if (snow1 >= snow2 && snow1 >= snow3 && snow1 > 0) {
            snow1 -= 3;
            if (snow1 < 0) snow1 = 0;
            cout << "Clearing Road 1\n";
        }
        else if (snow2 >= snow1 && snow2 >= snow3 && snow2 > 0) {
            snow2 -= 3;
            if (snow2 < 0) snow2 = 0;
            cout << "Clearing Road 2\n";
        }
        else if (snow3 > 0) {
            snow3 -= 3;
            if (snow3 < 0) snow3 = 0;
            cout << "Clearing Road 3\n";
        }

        completedRounds++;

        cout << "Remaining snow: "
             << snow1 << ", " << snow2 << ", " << snow3 << "\n";
    }

    cout << "\nFinal snow levels:\n";
    cout << "Road 1: " << snow1 << "\n";
    cout << "Road 2: " << snow2 << "\n";
    cout << "Road 3: " << snow3 << "\n";
    cout << "Rounds completed: " << completedRounds << "\n";

    return 0;
}

// Important logic:
// - while maximum rounds ko enforce karta hai.
// - Har round mein deepest snow wali road select hoti hai.
// - Snow depth negative ho jaaye toh zero set hoti hai.
// - Equal depths par comparison order lower-numbered road ko priority deta hai.
