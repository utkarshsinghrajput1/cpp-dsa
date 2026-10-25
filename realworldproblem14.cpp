// Problem 14: Railway Waiting-List Manager
// Real-world question: Train mein 5 confirmed seats aur 3 waiting-list slots hain. Booking request aane par pehle confirmed seat do. Seats full hon toh waiting list mein add karo. Waiting list bhi full ho toh booking reject karo. Cancellation par ek confirmed seat free ho jaati hai aur waiting list se ek passenger confirm ho sakta hai.

#include <iostream>
using namespace std;

int main() {
    int seatCapacity = 5;
    int occupiedSeats = 5;

    int waitingCapacity = 3;
    int waitingCount = 2;

    int bookings = 4;
    int rejected = 0;

    for (int i = 1; i <= bookings; i++) {

        // First, check for a confirmed seat
        if (occupiedSeats < seatCapacity) {
            occupiedSeats++;
            cout << "Booking " << i << ": Confirmed seat\n";
        }

        // If confirmed seats are full, try the waiting list
        else if (waitingCount < waitingCapacity) {
            waitingCount++;
            cout << "Booking " << i << ": Added to waiting list\n";
        }

        // Reject only when both capacities are full
        else {
            rejected++;
            cout << "Booking " << i << ": Rejected\n";
        }
    }

    cout << "\nBefore cancellation:\n";
    cout << "Occupied seats: " << occupiedSeats << "\n";
    cout << "Waiting list: " << waitingCount << "\n";

    // Simulate one confirmed passenger cancelling
    if (occupiedSeats > 0) {
        occupiedSeats--;

        // Promote one waiting passenger into the free seat
        if (waitingCount > 0) {
            occupiedSeats++;
            waitingCount--;
            cout << "\nOne waiting passenger is now confirmed.\n";
        }
    }

    cout << "\nFinal confirmed seats: " << occupiedSeats << "\n";
    cout << "Final waiting list: " << waitingCount << "\n";
    cout << "Rejected bookings: " << rejected << "\n";

    return 0;
}

// Important logic:
// - Confirmed seats aur waiting-list slots alag capacities hain.
// - Booking ke waqt confirmed seat ko priority milti hai.
// - Cancellation ke baad waiting passenger ko promote kiya jaata hai.
// - Limitation: Is simplified example mein waiting-list order ko individual passengers ke through track nahi kiya gaya; sirf total count track hota hai.
