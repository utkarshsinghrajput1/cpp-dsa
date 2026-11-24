// 50. Smart City Public Transport Capacity Planner
// Final Challenge
// Problem: Ek city mein R bus routes hain aur har route par B buses operate karti hain.

// Har bus ke liye:
// - Maximum passenger capacity input lo.
// - Expected passenger demand input lo.
// - Agar demand capacity se zyada hai toh extra passengers calculate karo.
// - Agar demand capacity ke 50% se kam hai toh underutilized bus mark karo.
// - Agar demand capacity se zyada hai toh overloaded bus mark karo.
// - Har route ke total passengers aur total extra passengers calculate karo.
// - City ke total passengers, overloaded buses aur underutilized buses calculate karo.
#include <iostream>
using namespace std;

int main() {
    int R, B;
    cin >> R >> B;

    int cityPassengers = 0;
    int cityExtra = 0;
    int overloaded = 0;
    int underutilized = 0;

    // Check every route
    for (int route = 1; route <= R; route++) {

        int routePassengers = 0;
        int routeExtra = 0;

        // Check every bus on the route
        for (int bus = 1; bus <= B; bus++) {

            int capacity, demand;
            cin >> capacity >> demand;

            if (capacity <= 0 || demand < 0) {
                cout << "Invalid Bus Data" << endl;
            } else {

                routePassengers = routePassengers + demand;

                // Overloaded bus
                if (demand > capacity) {
                    int extra = demand - capacity;

                    routeExtra = routeExtra + extra;
                    overloaded++;

                    cout << "Overloaded Bus" << endl;
                }

                // Underutilized bus
                else if (demand * 2 < capacity) {
                    underutilized++;

                    cout << "Underutilized Bus" << endl;
                }

                // Normal bus
                else {
                    cout << "Normal Bus" << endl;
                }
            }
        }

        cityPassengers = cityPassengers + routePassengers;
        cityExtra = cityExtra + routeExtra;

        cout << "Route " << route << " Passengers: "
             << routePassengers << endl;

        cout << "Route " << route << " Extra Demand: "
             << routeExtra << endl;
    }

    cout << "\nCITY REPORT" << endl;
    cout << "Total Passengers: " << cityPassengers << endl;
    cout << "Extra Passenger Demand: " << cityExtra << endl;
    cout << "Overloaded Buses: " << overloaded << endl;
    cout << "Underutilized Buses: " << underutilized << endl;

    return 0;
}