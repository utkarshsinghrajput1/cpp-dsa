// 6. Warehouse Stock Replenishment
// Problem: Warehouse ke N products ke current stock aur daily demand input lo. Calculate karo kitne din mein stock khatam hoga. Agar stock 7 din se kam chalega toh reorder alert print karo.

#include <iostream>
using namespace std;

int main() {
    int N, stock, demand;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> stock >> demand;

        if (demand <= 0) {
            cout << "Invalid demand" << endl;
        } else {
            int days = 0;

            while (stock >= demand) {
                stock = stock - demand;
                days++;
            }

            cout << "Product " << i << ": " << days << " days";

            if (days < 7)
                cout << " REORDER";

            cout << endl;
        }
    }

    return 0;
}