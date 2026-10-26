// Problem 17: Smart Irrigation System
// Question: 3 farms ki soil moisture alag hai. Har round mein sabse kam moisture wale farm ko water do. Water supply limited hai. Farm ko water tab tak do jab tak uski moisture target tak na pahunch jaaye ya water khatam na ho.

#include <iostream>
using namespace std;

int main() {
    int moisture1 = 20;
    int moisture2 = 35;
    int moisture3 = 25;

    int water = 12;
    int target = 40;
    int rounds = 0;

    while (water > 0) {
        // Stop when all farms reach the target
        if (moisture1 >= target &&
            moisture2 >= target &&
            moisture3 >= target) {
            break;
        }

        // Choose the lowest-moisture farm that needs water
        if (moisture1 < moisture2 &&
            moisture1 < moisture3 &&
            moisture1 < target) {
            moisture1 += 5;
        }
        else if (moisture2 <= moisture1 &&
                 moisture2 <= moisture3 &&
                 moisture2 < target) {
            moisture2 += 5;
        }
        else if (moisture3 < target) {
            moisture3 += 5;
        }
        else {
            break;
        }

        // One water unit is consumed per irrigation round
        water--;
        rounds++;

        cout << "Round " << rounds << ": "
             << moisture1 << ", "
             << moisture2 << ", "
             << moisture3 << "\n";
    }

    cout << "\nFinal moisture levels:\n";
    cout << "Farm 1: " << moisture1 << "\n";
    cout << "Farm 2: " << moisture2 << "\n";
    cout << "Farm 3: " << moisture3 << "\n";
    cout << "Water remaining: " << water << "\n";

    return 0;
}

// Important logic:
// - while loop water available hone tak repeat karta hai.
// - Minimum moisture wala eligible farm choose hota hai.
// - Har round mein ek water unit consume hota hai.
// - Moisture target se 5 points upar ja sakti hai, kyunki increments fixed hain; real system mein isko cap karna chahiye.
