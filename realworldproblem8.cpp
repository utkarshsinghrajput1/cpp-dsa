// Question 8 — City Water Crisis Management System
// Problem statement
// A city has three reservoirs. Every day, each reservoir receives new water and serves a particular consumer category:
// - Reservoir 1: hospitals
// - Reservoir 2: residential areas
// - Reservoir 3: industries
// Water is limited. The program must supply hospitals first, protect the minimum household requirement whenever possible, and restrict industrial use during shortages.

// For this version, reservoirs are independent, with no water transfers between them.

#include <iostream>
using namespace std;

int main() {
    int days;
    int water1, water2, water3;
    int capacity1, capacity2, capacity3;
    int hospitalMin, homeMin;

    cout << "Enter number of days: ";
    cin >> days;

    cout << "Enter initial water in 3 reservoirs: ";
    cin >> water1 >> water2 >> water3;

    cout << "Enter capacities of 3 reservoirs: ";
    cin >> capacity1 >> capacity2 >> capacity3;

    cout << "Enter minimum hospital and household supply: ";
    cin >> hospitalMin >> homeMin;

    if (days < 0 || water1 < 0 || water2 < 0 || water3 < 0 ||
        capacity1 <= 0 || capacity2 <= 0 || capacity3 <= 0 ||
        water1 > capacity1 || water2 > capacity2 ||
        water3 > capacity3 || hospitalMin < 0 || homeMin < 0) {
        cout << "Invalid input.\n";
        return 0;
    }

    int shortageDays = 0;
    int day = 1;

    while (day <= days) {
        int inflow1, inflow2, inflow3;
        int demandHospital, demandHome, demandIndustry;

        cout << "\nDay " << day << "\n";

        cout << "Enter water inflow for 3 reservoirs: ";
        cin >> inflow1 >> inflow2 >> inflow3;

        cout << "Enter hospital, home and industry demand: ";
        cin >> demandHospital >> demandHome >> demandIndustry;

        if (inflow1 < 0 || inflow2 < 0 || inflow3 < 0 ||
            demandHospital < 0 || demandHome < 0 ||
            demandIndustry < 0) {
            cout << "Invalid input. Try again.\n";
            continue;
        }

        // Add inflows without exceeding reservoir capacity.
        water1 += inflow1;
        if (water1 > capacity1) water1 = capacity1;

        water2 += inflow2;
        if (water2 > capacity2) water2 = capacity2;

        water3 += inflow3;
        if (water3 > capacity3) water3 = capacity3;

        // Hospitals receive water first.
        int hospitalSupply = demandHospital;
        if (hospitalSupply > water1)
            hospitalSupply = water1;

        water1 -= hospitalSupply;

        // Households receive water from reservoir 2.
        int homeSupply = demandHome;
        if (homeSupply > water2)
            homeSupply = water2;

        water2 -= homeSupply;

        // Industries receive only the available remaining stock.
        int industrySupply = demandIndustry;
        if (industrySupply > water3)
            industrySupply = water3;

        water3 -= industrySupply;

        // Check minimum requirements.
        if (hospitalSupply < hospitalMin ||
            homeSupply < homeMin) {
            shortageDays++;
            cout << "WATER SHORTAGE WARNING!\n";
        }

        cout << "Hospital supply: " << hospitalSupply << "\n";
        cout << "Household supply: " << homeSupply << "\n";
        cout << "Industry supply: " << industrySupply << "\n";

        cout << "Remaining water: "
             << water1 << ", " << water2 << ", "
             << water3 << "\n";

        if (water1 + water2 + water3 == 0) {
            cout << "All emergency reserves are exhausted.\n";
            break;
        }

        day++;
    }

    cout << "\nDays with minimum-supply shortages: "
         << shortageDays << "\n";

    return 0;
}


// Important logic
// - Inflow is added before distribution.
// - Reservoir levels cannot exceed their capacities.
// - Supply is limited to the demand and available water.
// - A warning is generated if hospital or household supply falls below its specified minimum.
// The model does not yet transfer water between reservoirs or calculate transfer costs.
