// 27. Water Distribution Management
// Problem: City mein N households hain. Har household ki water demand aur supplied water input lo. Calculate karo kitna water shortage hai aur total shortage kitni hai.
#include <iostream>
using namespace std;

int main() {
    int N;
    double demand, supplied, shortage, total = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> demand >> supplied;

        if (supplied < demand) {
            shortage = demand - supplied;
            total = total + shortage;

            cout << "House " << i
                 << " Shortage: " << shortage << endl;
        } else {
            cout << "House " << i << ": FULL SUPPLY" << endl;
        }
    }

    cout << "City Water Shortage: " << total;

    return 0;
}