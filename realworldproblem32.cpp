// Problem 32: Smart Hotel Room Allocation
// Question: Hotel mein single, double aur family rooms hain. Unki capacities 1, 2 aur 4 guests hain. Har guest group ke liye sabse chhota suitable room allocate karo. Rooms ki availability limited hai.

#include <iostream>
using namespace std;

int main() {
    int singleRooms = 3;
    int doubleRooms = 2;
    int familyRooms = 2;

    int bookings;
    int rejected = 0;

    cout << "Enter number of bookings: ";
    cin >> bookings;

    for (int i = 1; i <= bookings; i++) {
        int guests;

        cout << "Enter guest count: ";
        cin >> guests;

        if (guests <= 0 || guests > 4) {
            rejected++;
            cout << "Invalid group size\n";
        }
        // Allocate the smallest suitable available room
        else if (guests == 1 && singleRooms > 0) {
            singleRooms--;
            cout << "Single room assigned\n";
        }
        else if (guests <= 2 && doubleRooms > 0) {
            doubleRooms--;
            cout << "Double room assigned\n";
        }
        else if (familyRooms > 0) {
            familyRooms--;
            cout << "Family room assigned\n";
        }
        else {
            rejected++;
            cout << "No suitable room available\n";
        }
    }

    cout << "\nRemaining single rooms: " << singleRooms << "\n";
    cout << "Remaining double rooms: " << doubleRooms << "\n";
    cout << "Remaining family rooms: " << familyRooms << "\n";
    cout << "Rejected bookings: " << rejected << "\n";

    return 0;
}

// Important logic:
// - Single room ko pehle try kiya jaata hai.
// - Room unavailable ho toh next suitable category check hoti hai.
// - Guest group ko split nahi kiya jaata.
// - Budget aur room prices is simplified version mein included nahi hain.
