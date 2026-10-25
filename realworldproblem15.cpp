// Problem 15: Smart Elevator Load Manager
// Real-world question: Elevator ki maximum capacity 500 kg hai. Har request mein passengers ka total weight diya gaya hai. Elevator sirf tab request accept kare jab requested passengers ka total weight capacity ke andar ho. 5 requests process karo.

#include <iostream>
using namespace std;

int main() {
    int maxCapacity = 500;
    int currentWeight = 0;

    int requests = 5;
    int accepted = 0;
    int rejected = 0;

    // Example passenger-group weights in kilograms
    int weight;

    for (int i = 1; i <= requests; i++) {
        cout << "Enter total passenger weight for request "
             << i << ": ";
        cin >> weight;

        // Negative weight is invalid input
        if (weight < 0) {
            cout << "Invalid weight. Request rejected.\n";
            rejected++;
        }

        // Check whether the new group fits within capacity
        else if (currentWeight + weight <= maxCapacity) {
            currentWeight = currentWeight + weight;
            accepted++;

            cout << "Request accepted.\n";
            cout << "Current elevator load: "
                 << currentWeight << " kg\n";
        }

        // Do not allow the elevator to exceed its limit
        else {
            rejected++;
            cout << "Request rejected: Capacity exceeded.\n";
        }
    }

    cout << "\nAccepted requests: " << accepted << "\n";
    cout << "Rejected requests: " << rejected << "\n";
    cout << "Final load: " << currentWeight << " kg\n";
    cout << "Remaining capacity: "
         << maxCapacity - currentWeight << " kg\n";

    return 0;
}

// Important logic:
// - currentWeight + weight <= maxCapacity capacity check hai.
// - Rejected request elevator ka current load change nahi karti.
// - for loop exactly 5 requests process karta hai.
// - Limitation: Yeh simplified model elevator se passengers ke exit hone ko track nahi karta; har accepted request load mein add hoti hai.
