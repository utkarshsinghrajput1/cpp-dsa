// Problem 16: Restaurant Food-Waste Minimizer
// Question: Restaurant ke paas 3 ingredients ka limited stock hai. Har order ko ingredients ki fixed quantity chahiye. High-priority order pehle process karo. Order tabhi accept karo jab saare required ingredients available hon; warna reject karo.

#include <iostream>
using namespace std;

int main() {
    int rice = 20, vegetables = 15, cheese = 10;
    int accepted = 0, rejected = 0;

    // Order 1: High-priority meal
    int rice1 = 3, veg1 = 2, cheese1 = 1;

    // Order 2: Normal meal
    int rice2 = 4, veg2 = 3, cheese2 = 2;

    // Order 3: Special meal
    int rice3 = 5, veg3 = 4, cheese3 = 3;

    // Process high-priority order first
    if (rice >= rice1 && vegetables >= veg1 && cheese >= cheese1) {
        rice -= rice1;
        vegetables -= veg1;
        cheese -= cheese1;
        accepted++;
        cout << "Order 1 accepted\n";
    } else {
        rejected++;
        cout << "Order 1 rejected\n";
    }

    // Process second order using remaining stock
    if (rice >= rice2 && vegetables >= veg2 && cheese >= cheese2) {
        rice -= rice2;
        vegetables -= veg2;
        cheese -= cheese2;
        accepted++;
        cout << "Order 2 accepted\n";
    } else {
        rejected++;
        cout << "Order 2 rejected\n";
    }

    // Process third order
    if (rice >= rice3 && vegetables >= veg3 && cheese >= cheese3) {
        rice -= rice3;
        vegetables -= veg3;
        cheese -= cheese3;
        accepted++;
        cout << "Order 3 accepted\n";
    } else {
        rejected++;
        cout << "Order 3 rejected\n";
    }

    cout << "\nAccepted orders: " << accepted << "\n";
    cout << "Rejected orders: " << rejected << "\n";
    cout << "Remaining rice: " << rice << "\n";
    cout << "Remaining vegetables: " << vegetables << "\n";
    cout << "Remaining cheese: " << cheese << "\n";

    return 0;
}

// Important logic:
// - && ensure karta hai ki teeno ingredients available hon.
// - Order accept hone par hi stock decrease hota hai.
// - Fixed order processing se priority maintain hoti hai.
