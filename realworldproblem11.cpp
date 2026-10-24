// Problem 11: Smart Parking Tower Controller
// Real-world question: Ek parking tower mein 3 floors hain. Har floor ki capacity alag hai. Har incoming car ko us floor par park karo jahan sabse zyada spaces available hain. Agar tie ho, toh lower-numbered floor select karo. Parking full ho toh car reject karo.

// Input example:
// - Floor 1 capacity: 5, occupied: 3
// - Floor 2 capacity: 6, occupied: 2
// - Floor 3 capacity: 4, occupied: 1
// - Incoming cars: 3
// Expected logic: Har incoming car ke liye available spaces compare karo aur best floor select karo.

#include <iostream>
using namespace std;

int main() {
    int cap1 = 5, cap2 = 6, cap3 = 4;
    int car1 = 3, car2 = 2, car3 = 1;

    int incomingCars = 3;
    int rejected = 0;

    for (int i = 1; i <= incomingCars; i++) {

        // Calculate available spaces on every floor
        int free1 = cap1 - car1;
        int free2 = cap2 - car2;
        int free3 = cap3 - car3;

        // If every floor is full, reject the incoming car
        if (free1 == 0 && free2 == 0 && free3 == 0) {
            rejected++;
            cout << "Car " << i << ": Parking full, rejected\n";
        }

        // Strict comparisons preserve the lower floor number on ties
        else if (free1 >= free2 && free1 >= free3) {
            car1++;
            cout << "Car " << i << ": Parked on Floor 1\n";
        }
        else if (free2 >= free1 && free2 >= free3) {
            car2++;
            cout << "Car " << i << ": Parked on Floor 2\n";
        }
        else {
            car3++;
            cout << "Car " << i << ": Parked on Floor 3\n";
        }
    }

    cout << "\nFinal Occupancy:\n";
    cout << "Floor 1: " << car1 << "/" << cap1 << "\n";
    cout << "Floor 2: " << car2 << "/" << cap2 << "\n";
    cout << "Floor 3: " << car3 << "/" << cap3 << "\n";
    cout << "Rejected Cars: " << rejected << "\n";

    return 0;
}
// Important logic:
// - for loop har incoming car ko process karta hai.
// - free1, free2, free3 available parking spaces calculate karte hain.
// - >= comparison tie hone par lower-numbered floor ko priority deta hai.
// - Occupancy kabhi capacity se exceed nahi karti.
