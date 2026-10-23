// Question 7 — Smart Electricity Blackout Prevention System
// Problem statement
// A city has three consumer categories: hospitals, homes and factories. Each hour, the program receives their demand and the available electricity generation.

// Hospitals have the highest priority, followed by homes and factories. The grid must never distribute more electricity than it has available.

#include <iostream>
using namespace std;

int main() {
    int hours, generation;
    int hospitalDemand, homeDemand, factoryDemand;
    int criticalLevel;

    cout << "Enter number of hours: ";
    cin >> hours;

    cout << "Enter emergency generation threshold: ";
    cin >> criticalLevel;

    if (hours < 0 || criticalLevel < 0) {
        cout << "Invalid input.\n";
        return 0;
    }

    int hour = 1;
    int totalDelivered = 0;
    int totalUnmet = 0;
    int warnings = 0;

    while (hour <= hours) {
        cout << "\nHour " << hour << "\n";

        cout << "Enter generation available: ";
        cin >> generation;

        cout << "Enter hospital, home and factory demand: ";
        cin >> hospitalDemand >> homeDemand >> factoryDemand;

        if (generation < 0 || hospitalDemand < 0 ||
            homeDemand < 0 || factoryDemand < 0) {
            cout << "Invalid input. Try again.\n";
            continue;
        }

        int remaining = generation;

        // Hospitals receive electricity first.
        int hospitalSupply = hospitalDemand;
        if (hospitalSupply > remaining)
            hospitalSupply = remaining;

        remaining -= hospitalSupply;

        // Homes receive electricity second.
        int homeSupply = homeDemand;
        if (homeSupply > remaining)
            homeSupply = remaining;

        remaining -= homeSupply;

        // Factories receive the remaining electricity.
        int factorySupply = factoryDemand;
        if (factorySupply > remaining)
            factorySupply = remaining;

        remaining -= factorySupply;

        int delivered =
            hospitalSupply + homeSupply + factorySupply;

        int unmet =
            hospitalDemand + homeDemand + factoryDemand - delivered;

        totalDelivered += delivered;
        totalUnmet += unmet;

        if (generation < criticalLevel) {
            warnings++;
            cout << "EMERGENCY: Low electricity generation!\n";
        }

        cout << "Hospital supply: " << hospitalSupply << "\n";
        cout << "Home supply: " << homeSupply << "\n";
        cout << "Factory supply: " << factorySupply << "\n";
        cout << "Unmet demand: " << unmet << "\n";

        hour++;
    }

    cout << "\nTotal electricity delivered: " << totalDelivered;
    cout << "\nTotal unmet demand: " << totalUnmet;
    cout << "\nEmergency warnings: " << warnings << "\n";

    return 0;
}

// Important logic
// The variable remaining is reduced after every allocation. This ensures that the total distributed electricity never exceeds the available generation.

// This version gives hospitals priority, then homes, then factories. It does not implement minimum supply guarantees or generator failures; those can be added as further constraints.
