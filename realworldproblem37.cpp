// Problem 37: Multi-Stage Parcel Delivery Controller
// Question: 3 parcels ko warehouse, sorting center aur delivery hub se pass hona hai. Har parcel ka stage 0 se start hota hai. Har round mein parcel ek stage aage badhta hai. Total 3 rounds ke baad parcel stage 3 par ho toh delivered mark karo.

#include <iostream>
using namespace std;

int main() {
    int parcel1 = 0;
    int parcel2 = 0;
    int parcel3 = 0;

    int rounds = 3;

    // Each round advances every parcel by one stage
    for (int i = 1; i <= rounds; i++) {
        if (parcel1 < 3) parcel1++;
        if (parcel2 < 3) parcel2++;
        if (parcel3 < 3) parcel3++;

        cout << "Round " << i << ": ";
        cout << parcel1 << ", " << parcel2 << ", " << parcel3 << "\n";
    }

    // Stage 3 means the parcel has completed all delivery stages
    int delivered = 0;

    if (parcel1 == 3) delivered++;
    if (parcel2 == 3) delivered++;
    if (parcel3 == 3) delivered++;

    cout << "\nDelivered parcels: " << delivered << "\n";

    return 0;
}

// Important logic:
// - Har parcel ka stage alag variable mein store hota hai.
// - for loop har round ko simulate karta hai.
// - Stage 3 par parcel ki progress aage nahi badhti.
// - Is simplified example mein capacity, deadlines aur failed-delivery retries include nahi hain.
