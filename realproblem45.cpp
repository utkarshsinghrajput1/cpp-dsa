// 45. ATM Cash Denomination Distributor
// Problem: ATM ko ek amount dispense karna hai. Available notes ₹500, ₹200, ₹100 aur ₹50 ke hain. Har denomination ka maximum possible count use karke amount dispense karo. Agar amount 50 se divisible nahi hai toh reject karo.
#include <iostream>
using namespace std;

int main() {
    int amount;
    cin >> amount;

    if (amount <= 0 || amount % 50 != 0) {
        cout << "INVALID AMOUNT";
    } else {
        int notes500 = 0;
        int notes200 = 0;
        int notes100 = 0;
        int notes50 = 0;

        while (amount >= 500) {
            amount = amount - 500;
            notes500++;
        }

        while (amount >= 200) {
            amount = amount - 200;
            notes200++;
        }

        while (amount >= 100) {
            amount = amount - 100;
            notes100++;
        }

        while (amount >= 50) {
            amount = amount - 50;
            notes50++;
        }

        cout << "500 Notes: " << notes500 << endl;
        cout << "200 Notes: " << notes200 << endl;
        cout << "100 Notes: " << notes100 << endl;
        cout << "50 Notes: " << notes50;
    }

    return 0;
}