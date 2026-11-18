// 29. School Bus Route Capacity
// Problem: School ke B buses hain. Har bus ki seating capacity S hai. Students ki total count N input lo. Buses mein students allocate karo aur last bus mein kitni seats empty hain calculate karo.
#include <iostream>
using namespace std;

int main() {
    int B, S, N;
    cin >> B >> S >> N;

    int remaining = N;

    for (int bus = 1; bus <= B; bus++) {
        int assigned = 0;

        while (assigned < S && remaining > 0) {
            assigned++;
            remaining--;
        }

        cout << "Bus " << bus
             << " Students: " << assigned
             << " Empty Seats: " << S - assigned
             << endl;
    }

    cout << "Students without seats: " << remaining;
    return 0;
}