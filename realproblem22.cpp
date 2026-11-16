// 22. Hospital Bed Allocation
// Problem: Hospital mein W wards hain aur har ward mein B beds hain. Har ward ke occupied beds input lo. Available beds calculate karo. Agar kisi ward mein 90% se zyada beds occupied hain toh emergency alert do.
#include <iostream>
using namespace std;

int main() {
    int W, B, occupied;
    cin >> W >> B;

    int totalAvailable = 0;

    for (int i = 1; i <= W; i++) {
        cin >> occupied;

        if (occupied < 0 || occupied > B) {
            cout << "Invalid Data" << endl;
        } else {
            int available = B - occupied;
            totalAvailable = totalAvailable + available;

            cout << "Ward " << i
                 << " Available: " << available << endl;

            if (occupied * 100 > B * 90)
                cout << "EMERGENCY ALERT" << endl;
        }
    }

    cout << "Total Available Beds: " << totalAvailable;
    return 0;
}