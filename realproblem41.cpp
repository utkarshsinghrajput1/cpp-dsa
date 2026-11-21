// 41. Hotel Room Occupancy Manager
// Problem: Hotel mein F floors hain aur har floor par R rooms hain. Har room ka status input lo: 1 occupied, 0 vacant. Nested loops se total occupied aur vacant rooms count karo. Har floor ki occupancy bhi print karo.
#include <iostream>
using namespace std;

int main() {
    int F, R, status;
    int occupied = 0, vacant = 0;

    cin >> F >> R;

    for (int floor = 1; floor <= F; floor++) {
        int floorOccupied = 0;

        for (int room = 1; room <= R; room++) {
            cin >> status;

            if (status == 1) {
                occupied++;
                floorOccupied++;
            } else if (status == 0) {
                vacant++;
            }
        }

        cout << "Floor " << floor
             << " Occupied: " << floorOccupied << endl;
    }

    cout << "Total Occupied: " << occupied << endl;
    cout << "Total Vacant: " << vacant;

    return 0;
}