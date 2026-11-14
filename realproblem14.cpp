// 14. Elevator Load Safety Monitor
// Problem: Elevator ki maximum capacity aur N passengers ke individual weights input lo. Agar kisi passenger ko add karne se total weight capacity cross karta hai toh us passenger ko allow mat karo. Accepted passengers aur remaining capacity print karo.
#include <iostream>
using namespace std;

int main() {
    int N, accepted = 0;
    double capacity, weight, total = 0;
    cin >> capacity >> N;

    for (int i = 1; i <= N; i++) {
        cin >> weight;

        if (weight <= 0) {
            cout << "Invalid weight" << endl;
        } else if (total + weight <= capacity) {
            total = total + weight;
            accepted++;
            cout << "Passenger Accepted" << endl;
        } else {
            cout << "Passenger Rejected" << endl;
        }
    }

    cout << "Accepted: " << accepted << endl;
    cout << "Remaining Capacity: " << capacity - total;

    return 0;
}