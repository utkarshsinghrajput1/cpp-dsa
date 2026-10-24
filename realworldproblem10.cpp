// Question 10 — AI Data Center Thermal Emergency Simulator
// Problem statement
// A data center has four server racks. Each rack has a starting temperature, temperature rise, cooling rate, warning temperature, critical temperature, workload and maximum workload capacity.

// Every minute, the program must:
// 1. Update the temperature of active racks.
// 2. Reduce workload when a rack reaches its warning temperature.
// 3. Shut down a rack when its temperature reaches the critical temperature.
// 4. Attempt to redistribute a shut-down rack's remaining workload.
// 5. Trigger an emergency if redistribution is impossible.
// 6. Never exceed the total power limit.
// For this simplified model, workload units represent power units. Temperature changes by a fixed amount per minute. A rack is shut down permanently once it reaches its critical temperature.

#include <iostream>
using namespace std;

int main() {
    int T, powerLimit;

    int temp1, temp2, temp3, temp4;
    int rise1, rise2, rise3, rise4;
    int cool1, cool2, cool3, cool4;
    int warn1, warn2, warn3, warn4;
    int critical1, critical2, critical3, critical4;
    int load1, load2, load3, load4;
    int max1, max2, max3, max4;

    cout << "Enter simulation minutes and power limit: ";
    cin >> T >> powerLimit;

    cout << "Enter starting temperatures of 4 racks: ";
    cin >> temp1 >> temp2 >> temp3 >> temp4;

    cout << "Enter temperature rise per minute: ";
    cin >> rise1 >> rise2 >> rise3 >> rise4;

    cout << "Enter cooling rate per minute: ";
    cin >> cool1 >> cool2 >> cool3 >> cool4;

    cout << "Enter warning temperatures: ";
    cin >> warn1 >> warn2 >> warn3 >> warn4;

    cout << "Enter critical temperatures: ";
    cin >> critical1 >> critical2 >> critical3 >> critical4;

    cout << "Enter starting workloads: ";
    cin >> load1 >> load2 >> load3 >> load4;

    cout << "Enter maximum workload capacities: ";
    cin >> max1 >> max2 >> max3 >> max4;

    if (T < 0 || powerLimit <= 0 ||
        rise1 < 0 || rise2 < 0 || rise3 < 0 || rise4 < 0 ||
        cool1 < 0 || cool2 < 0 || cool3 < 0 || cool4 < 0 ||
        load1 < 0 || load2 < 0 || load3 < 0 || load4 < 0 ||
        max1 <= 0 || max2 <= 0 || max3 <= 0 || max4 <= 0 ||
        load1 > max1 || load2 > max2 ||
        load3 > max3 || load4 > max4 ||
        temp1 >= critical1 || temp2 >= critical2 ||
        temp3 >= critical3 || temp4 >= critical4 ||
        warn1 >= critical1 || warn2 >= critical2 ||
        warn3 >= critical3 || warn4 >= critical4 ||
        load1 + load2 + load3 + load4 > powerLimit) {

        cout << "Invalid input or initial power overload.\n";
        return 0;
    }

    int active1 = 1, active2 = 1;
    int active3 = 1, active4 = 1;

    int emergencyCount = 0;
    int totalEnergy = 0;
    int minute = 1;

    while (minute <= T) {
        // Stop if every rack is shut down.
        if (active1 == 0 && active2 == 0 &&
            active3 == 0 && active4 == 0) {
            cout << "All racks are shut down.\n";
            break;
        }

        cout << "\nMinute " << minute << "\n";

        // Update temperatures of active racks.
        if (active1 == 1) {
            temp1 = temp1 + rise1 - cool1;
        }

        if (active2 == 1) {
            temp2 = temp2 + rise2 - cool2;
        }

        if (active3 == 1) {
            temp3 = temp3 + rise3 - cool3;
        }

        if (active4 == 1) {
            temp4 = temp4 + rise4 - cool4;
        }

        // Warning: reduce workload by one power unit.
        if (active1 == 1 && temp1 >= warn1 && load1 > 0)
            load1--;

        if (active2 == 1 && temp2 >= warn2 && load2 > 0)
            load2--;

        if (active3 == 1 && temp3 >= warn3 && load3 > 0)
            load3--;

        if (active4 == 1 && temp4 >= warn4 && load4 > 0)
            load4--;

        // Critical rack: shut down and save its remaining workload.
        int transfer = 0;

        if (active1 == 1 && temp1 >= critical1) {
            transfer = load1;
            load1 = 0;
            active1 = 0;

            // Try to transfer workload to rack 2.
            if (active2 == 1 && max2 - load2 >= transfer) {
                load2 += transfer;
                transfer = 0;
            }

            if (transfer > 0 && active3 == 1 &&
                max3 - load3 >= transfer) {
                load3 += transfer;
                transfer = 0;
            }

            if (transfer > 0 && active4 == 1 &&
                max4 - load4 >= transfer) {
                load4 += transfer;
                transfer = 0;
            }

            if (transfer > 0) {
                emergencyCount++;
                cout << "Emergency: Rack 1 workload could not be moved.\n";
            }
        }

        transfer = 0;

        if (active2 == 1 && temp2 >= critical2) {
            transfer = load2;
            load2 = 0;
            active2 = 0;

            if (active1 == 1 && max1 - load1 >= transfer) {
                load1 += transfer;
                transfer = 0;
            }

            if (transfer > 0 && active3 == 1 &&
                max3 - load3 >= transfer) {
                load3 += transfer;
                transfer = 0;
            }

            if (transfer > 0 && active4 == 1 &&
                max4 - load4 >= transfer) {
                load4 += transfer;
                transfer = 0;
            }

            if (transfer > 0) {
                emergencyCount++;
                cout << "Emergency: Rack 2 workload could not be moved.\n";
            }
        }

        transfer = 0;

        if (active3 == 1 && temp3 >= critical3) {
            transfer = load3;
            load3 = 0;
            active3 = 0;

            if (active1 == 1 && max1 - load1 >= transfer) {
                load1 += transfer;
                transfer = 0;
            }

            if (transfer > 0 && active2 == 1 &&
                max2 - load2 >= transfer) {
                load2 += transfer;
                transfer = 0;
            }

            if (transfer > 0 && active4 == 1 &&
                max4 - load4 >= transfer) {
                load4 += transfer;
                transfer = 0;
            }

            if (transfer > 0) {
                emergencyCount++;
                cout << "Emergency: Rack 3 workload could not be moved.\n";
            }
        }

        transfer = 0;

        if (active4 == 1 && temp4 >= critical4) {
            transfer = load4;
            load4 = 0;
            active4 = 0;

            if (active1 == 1 && max1 - load1 >= transfer) {
                load1 += transfer;
                transfer = 0;
            }

            if (transfer > 0 && active2 == 1 &&
                max2 - load2 >= transfer) {
                load2 += transfer;
                transfer = 0;
            }

            if (transfer > 0 && active3 == 1 &&
                max3 - load3 >= transfer) {
                load3 += transfer;
                transfer = 0;
            }

            if (transfer > 0) {
                emergencyCount++;
                cout << "Emergency: Rack 4 workload could not be moved.\n";
            }
        }

        int totalPower = load1 + load2 + load3 + load4;

        // Verify the power budget after workload redistribution.
        if (totalPower > powerLimit) {
            cout << "CRITICAL: Power limit exceeded!\n";
            emergencyCount++;
            break;
        }

        totalEnergy += totalPower;

        cout << "Temperatures: "
             << temp1 << ", " << temp2 << ", "
             << temp3 << ", " << temp4 << "\n";

        cout << "Active racks: "
             << active1 << ", " << active2 << ", "
             << active3 << ", " << active4 << "\n";

        cout << "Total power: " << totalPower << "\n";

        minute++;
    }

    cout << "\nSimulation finished.";
    cout << "\nMinutes simulated: " << minute - 1;
    cout << "\nTotal energy units: " << totalEnergy;
    cout << "\nEmergency count: " << emergencyCount;
    cout << "\nFinal rack states: "
         << active1 << ", " << active2 << ", "
         << active3 << ", " << active4 << "\n";

    return 0;
}





// Important logic
// - active1 through active4 indicate whether each rack is running. A value of 0 means shut down.
// - When a rack overheats, its remaining workload is moved to another active rack if that rack has enough spare capacity.
// - transfer stores the workload still waiting to be moved.
// - totalPower checks the combined workload after redistribution.
// - totalEnergy accumulates the power used in each simulated minute.
// Important limitation: This is a basic educational simulator, not a production-ready thermal model. Workload is redistributed in a fixed rack order, and a failed transfer triggers an emergency rather than automatically discarding workload. Temperature, cooling and workload are simplified to make the problem solvable using basic control flow.
