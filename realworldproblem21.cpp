// Problem 21: Public Bus Passenger Balancer
// Question: 3 buses ki capacity 40, 35 aur 30 passengers hai. Starting passenger counts 25, 30 aur 20 hain. Har stop par passengers board karte hain. Har request ko us bus mein bhejo jisme sabse zyada free seats hon. Capacity exceed ho toh request reject karo.

#include <iostream>
using namespace std;

int main() {
    int cap1 = 40, cap2 = 35, cap3 = 30;
    int bus1 = 25, bus2 = 30, bus3 = 20;

    int requests = 5;
    int rejected = 0;

    // Each request represents a group of passengers
    for (int i = 1; i <= requests; i++) {
        int group;
        cout << "Enter passenger group size: ";
        cin >> group;

        int free1 = cap1 - bus1;
        int free2 = cap2 - bus2;
        int free3 = cap3 - bus3;

        if (group <= 0) {
            cout << "Invalid group size\n";
            rejected++;
        }
        // Try the bus with the most free seats first
        else if (free1 >= group && free1 >= free2 && free1 >= free3) {
            bus1 += group;
            cout << "Group assigned to Bus 1\n";
        }
        else if (free2 >= group && free2 >= free3) {
            bus2 += group;
            cout << "Group assigned to Bus 2\n";
        }
        else if (free3 >= group) {
            bus3 += group;
            cout << "Group assigned to Bus 3\n";
        }
        else {
            rejected++;
            cout << "No bus has enough seats\n";
        }
    }

    cout << "\nBus 1 passengers: " << bus1 << "/" << cap1 << "\n";
    cout << "Bus 2 passengers: " << bus2 << "/" << cap2 << "\n";
    cout << "Bus 3 passengers: " << bus3 << "/" << cap3 << "\n";
    cout << "Rejected groups: " << rejected << "\n";

    return 0;
}

// Important logic:
// - Free seats pehle calculate hote hain.
// - Group ko split nahi kiya jaata.
// - Selected bus mein poora group fit hona chahiye.
// - Agar koi bus fit nahi kar sakti, request reject hoti hai.
