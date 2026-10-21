// Question 1 — Smart City Traffic Gridlock Controller
// Problem statement
// A city has four roads leading to an intersection. Each road has a queue of vehicles. The traffic controller runs for H minutes.

// The program must:
// 1. Take the initial vehicle count for each road.
// 2. Give the green signal to the road with the largest queue.
// 3. Allow up to K vehicles to pass per green signal.
// 4. If queues are equal, choose the road with the smaller road number.
// 5. Add new vehicles every P minutes.
// 6. Detect gridlock if every road exceeds the specified queue limit.
// 7. Stop when all queues become empty or H minutes have passed.
// Rules for this implementation
// - Road numbers are 1, 2, 3 and 4.
// - Every P minutes, fixed numbers of vehicles arrive on the four roads.
// - New vehicles arrive at the end of the minute, after the green signal.
// - Gridlock is checked after new arrivals.
// - A road passes at most K vehicles in one minute.
// - No arrays or functions are used.

#include <iostream>
using namespace std;

int main() {
    int road1, road2, road3, road4;
    int K, H, P, limit;
    int arrival1, arrival2, arrival3, arrival4;

    // Input initial traffic on each road
    cout << "Enter vehicles on roads 1, 2, 3, 4: ";
    cin >> road1 >> road2 >> road3 >> road4;

    cout << "Enter max vehicles per green signal (K): ";
    cin >> K;

    cout << "Enter total simulation minutes (H): ";
    cin >> H;

    cout << "Enter arrival interval (P): ";
    cin >> P;

    cout << "Enter gridlock queue limit: ";
    cin >> limit;

    cout << "Enter arrivals for roads 1, 2, 3, 4: ";
    cin >> arrival1 >> arrival2 >> arrival3 >> arrival4;

    // Validate basic inputs
    if (road1 < 0 || road2 < 0 || road3 < 0 || road4 < 0 ||
        K <= 0 || H <= 0 || P <= 0 || limit < 0 ||
        arrival1 < 0 || arrival2 < 0 ||
        arrival3 < 0 || arrival4 < 0) {

        cout << "Invalid input.\n";
        return 0;
    }

    int minute = 1;

    while (minute <= H) {

        // Stop if every road is empty
        if (road1 == 0 && road2 == 0 &&
            road3 == 0 && road4 == 0) {

            cout << "All roads are empty.\n";
            break;
        }

        // Choose the road with the largest queue.
        // Strict > comparisons preserve the smaller
        // road number when queues are equal.
        int largest = road1;
        int selectedRoad = 1;

        if (road2 > largest) {
            largest = road2;
            selectedRoad = 2;
        }

        if (road3 > largest) {
            largest = road3;
            selectedRoad = 3;
        }

        if (road4 > largest) {
            largest = road4;
            selectedRoad = 4;
        }

        // Let up to K vehicles pass
        int passed = 0;

        if (selectedRoad == 1) {
            if (road1 >= K) {
                passed = K;
            } else {
                passed = road1;
            }
            road1 = road1 - passed;
        }
        else if (selectedRoad == 2) {
            if (road2 >= K) {
                passed = K;
            } else {
                passed = road2;
            }
            road2 = road2 - passed;
        }
        else if (selectedRoad == 3) {
            if (road3 >= K) {
                passed = K;
            } else {
                passed = road3;
            }
            road3 = road3 - passed;
        }
        else {
            if (road4 >= K) {
                passed = K;
            } else {
                passed = road4;
            }
            road4 = road4 - passed;
        }

        cout << "\nMinute: " << minute;
        cout << "\nGreen signal: Road " << selectedRoad;
        cout << "\nVehicles passed: " << passed;

        // New vehicles arrive at the end of every P minutes
        if (minute % P == 0) {
            road1 = road1 + arrival1;
            road2 = road2 + arrival2;
            road3 = road3 + arrival3;
            road4 = road4 + arrival4;

            cout << "\nNew vehicles arrived.";
        }

        cout << "\nQueues: "
             << road1 << " " << road2 << " "
             << road3 << " " << road4 << "\n";

        // Gridlock means every queue exceeds the limit
        if (road1 > limit && road2 > limit &&
            road3 > limit && road4 > limit) {

            cout << "GRIDLOCK DETECTED!\n";
            break;
        }

        minute++;
    }

    cout << "\nFinal traffic queues:\n";
    cout << "Road 1: " << road1 << "\n";
    cout << "Road 2: " << road2 << "\n";
    cout << "Road 3: " << road3 << "\n";
    cout << "Road 4: " << road4 << "\n";

    return 0;
}

// Code ka logic samajh
// - while (minute <= H) poori simulation ko minute-by-minute chalata hai.
// - largest aur selectedRoad decide karte hain ki kis road ko green signal milega.
// - > comparison use karne se equal queues mein pehle wali, yaani chhoti road number, select hoti hai.
// - passed calculate karta hai ki maximum K vehicles mein se kitne actually pass hue.
// - minute % P == 0 arrival interval check karta hai.
// - Final if condition check karti hai ki saari chaar queues limit se strictly badi hain ya nahi.
// Example: agar queues 12, 12, 8, 4 hain aur K = 5, toh Road 1 select hogi aur uski queue 7 ho jayegi.
