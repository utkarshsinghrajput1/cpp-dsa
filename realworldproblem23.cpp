// Problem 23: Smart Library Book Circulation
// Question: Library mein 3 book categories hain. Har category ki total copies aur available copies track karo. Borrow requests aur return requests process karo. Available books se zyada borrowing aur total copies se zyada returns reject karo.

#include <iostream>
using namespace std;

int main() {
    int total1 = 10, total2 = 8, total3 = 6;
    int available1 = 5, available2 = 3, available3 = 2;

    int events;
    cout << "Enter number of events: ";
    cin >> events;

    int rejected = 0;

    for (int i = 1; i <= events; i++) {
        int category, action, quantity;

        cout << "Enter category (1-3), action (1=borrow, 2=return), quantity: ";
        cin >> category >> action >> quantity;

        if (quantity <= 0) {
            cout << "Invalid quantity\n";
            rejected++;
        }
        else if (category == 1) {
            if (action == 1 && available1 >= quantity) {
                available1 -= quantity;
                cout << "Borrow successful\n";
            }
            else if (action == 2 && available1 + quantity <= total1) {
                available1 += quantity;
                cout << "Return successful\n";
            }
            else {
                rejected++;
                cout << "Request rejected\n";
            }
        }
        else if (category == 2) {
            if (action == 1 && available2 >= quantity) {
                available2 -= quantity;
                cout << "Borrow successful\n";
            }
            else if (action == 2 && available2 + quantity <= total2) {
                available2 += quantity;
                cout << "Return successful\n";
            }
            else {
                rejected++;
                cout << "Request rejected\n";
            }
        }
        else if (category == 3) {
            if (action == 1 && available3 >= quantity) {
                available3 -= quantity;
                cout << "Borrow successful\n";
            }
            else if (action == 2 && available3 + quantity <= total3) {
                available3 += quantity;
                cout << "Return successful\n";
            }
            else {
                rejected++;
                cout << "Request rejected\n";
            }
        }
        else {
            rejected++;
            cout << "Invalid category\n";
        }
    }

    cout << "\nAvailable books:\n";
    cout << "Category 1: " << available1 << "\n";
    cout << "Category 2: " << available2 << "\n";
    cout << "Category 3: " << available3 << "\n";
    cout << "Rejected requests: " << rejected << "\n";

    return 0;
}

// Important logic:
// - category decide karta hai kaunsi inventory update hogi.
// - Borrow karne par available stock decrease hota hai.
// - Return par available stock total copies se exceed nahi kar sakta.
// - Yeh simplified version individual borrowers aur overdue dates track nahi karta.
