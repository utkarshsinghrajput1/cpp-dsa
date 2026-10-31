// Problem 35: Smart Retail Shelf Replenishment
// Question: Supermarket mein 3 products ki shelf aur stockroom quantities track karo. Har product ki shelf capacity 10 units hai. Shelf par 3 ya usse kam units bachne par stockroom se replenishment karo.

#include <iostream>
using namespace std;

int main() {
    int shelf1 = 3, stock1 = 8;
    int shelf2 = 7, stock2 = 5;
    int shelf3 = 2, stock3 = 6;

    int capacity = 10;

    // Check each product separately
    if (shelf1 <= 3) {
        int space = capacity - shelf1;

        // Transfer only what shelf space and stock allow
        int transfer = stock1;
        if (transfer > space) transfer = space;

        shelf1 += transfer;
        stock1 -= transfer;
    }

    if (shelf2 <= 3) {
        int space = capacity - shelf2;
        int transfer = stock2;
        if (transfer > space) transfer = space;

        shelf2 += transfer;
        stock2 -= transfer;
    }

    if (shelf3 <= 3) {
        int space = capacity - shelf3;
        int transfer = stock3;
        if (transfer > space) transfer = space;

        shelf3 += transfer;
        stock3 -= transfer;
    }

    cout << "Shelf 1: " << shelf1 << ", stockroom: " << stock1 << "\n";
    cout << "Shelf 2: " << shelf2 << ", stockroom: " << stock2 << "\n";
    cout << "Shelf 3: " << shelf3 << ", stockroom: " << stock3 << "\n";

    return 0;
}

// Important logic:
// - Replenishment sirf low-stock products ke liye hota hai.
// - space shelf ki remaining capacity calculate karta hai.
// - Transfer stockroom stock aur shelf space dono se limited hota hai.
// - Yeh example ek replenishment round simulate karta hai; daily sales aur lost sales add karke ise aur tough bana sakta hai.
