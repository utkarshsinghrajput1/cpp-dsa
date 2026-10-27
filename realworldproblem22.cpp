// Problem 22: ATM Cash-Denomination Manager
// Question: ATM ke paas ₹500, ₹200 aur ₹100 ke limited notes hain. Customer ka withdrawal amount exact notes se dena hai. Agar exact combination possible nahi hai, transaction reject karo.

#include <iostream>
using namespace std;

int main() {
    int notes500 = 2;
    int notes200 = 4;
    int notes100 = 5;

    int amount;
    cout << "Enter withdrawal amount: ";
    cin >> amount;

    int originalAmount = amount;
    int used500 = 0, used200 = 0, used100 = 0;

    if (amount <= 0 || amount % 100 != 0) {
        cout << "Invalid withdrawal amount\n";
        return 0;
    }

    // Try the largest denomination first
    while (amount >= 500 && notes500 > 0) {
        amount -= 500;
        notes500--;
        used500++;
    }

    // Then try 200-rupee notes
    while (amount >= 200 && notes200 > 0) {
        amount -= 200;
        notes200--;
        used200++;
    }

    // Finally try 100-rupee notes
    while (amount >= 100 && notes100 > 0) {
        amount -= 100;
        notes100--;
        used100++;
    }

    // If any amount remains, restore the notes used
    if (amount != 0) {
        notes500 += used500;
        notes200 += used200;
        notes100 += used100;

        cout << "Exact withdrawal not possible\n";
    } else {
        cout << "Withdrawal successful: Rs. " << originalAmount << "\n";
        cout << "500 notes: " << used500 << "\n";
        cout << "200 notes: " << used200 << "\n";
        cout << "100 notes: " << used100 << "\n";
    }

    cout << "Remaining notes: "
         << notes500 << " x 500, "
         << notes200 << " x 200, "
         << notes100 << " x 100\n";

    return 0;
}

// Important logic:
// - while loops available notes use karte hain.
// - Agar amount zero nahi hua, exact payment nahi hui.
// - Failure par used notes restore hote hain.
// - Challenge limitation: Greedy method har possible combination find nahi karta. Kuch amounts ke liye backtracking ya nested loops se alternate combinations check karne padenge.
