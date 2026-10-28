// Problem 25: Smart Waste Collection Scheduler
// Question: 3 zones mein waste levels alag hain. Truck har trip mein maximum 10 units waste collect kar sakta hai. Sabse zyada filled zone se waste collect karo jab tak truck capacity fill na ho ya waste khatam na ho.

#include <iostream>
using namespace std;

int main() {
    int waste1 = 12;
    int waste2 = 8;
    int waste3 = 15;

    int truckCapacity = 10;
    int collected = 0;

    while (truckCapacity > 0) {
        // Stop when no zone has waste left
        if (waste1 == 0 && waste2 == 0 && waste3 == 0) {
            break;
        }

        // Select the zone with the most waste
        if (waste1 >= waste2 && waste1 >= waste3 && waste1 > 0) {
            waste1--;
        }
        else if (waste2 >= waste1 && waste2 >= waste3 && waste2 > 0) {
            waste2--;
        }
        else if (waste3 > 0) {
            waste3--;
        }
        else {
            break;
        }

        // One unit collected per iteration
        truckCapacity--;
        collected++;
    }

    cout << "Waste collected: " << collected << "\n";
    cout << "Truck capacity remaining: " << truckCapacity << "\n";
    cout << "Zone 1 waste remaining: " << waste1 << "\n";
    cout << "Zone 2 waste remaining: " << waste2 << "\n";
    cout << "Zone 3 waste remaining: " << waste3 << "\n";

    return 0;
}

// Important logic:
// - while truck capacity remaining hone tak chalta hai.
// - Har iteration highest-waste zone se ek unit collect karti hai.
// - Waste aur truck capacity dono update hote hain.
// - Yeh simplified model har unit ko same size maanta hai.
