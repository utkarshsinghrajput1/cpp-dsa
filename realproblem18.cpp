// 18. Parking Lot Revenue System
// Problem: Parking lot mein N vehicles ke parking hours input lo. First 2 hours ₹30, next 3 hours ₹20/hour, uske baad ₹10/hour charge karo.
#include <iostream>
using namespace std;

int main() {
    int N, hours;
    int total = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> hours;

        int charge = 0;

        if (hours <= 2)
            charge = hours * 30;
        else if (hours <= 5)
            charge = 60 + (hours - 2) * 20;
        else
            charge = 60 + 60 + (hours - 5) * 10;

        total = total + charge;
        cout << "Vehicle " << i << ": " << charge << endl;
    }

    cout << "Parking Revenue: " << total;
    return 0;
}