// Problem 40: Smart City Multi-System Crisis Simulator
// Question: City ke 3 zones mein power, water aur medical supplies limited hain. Har round mein har zone ki demand process karo. Medical supplies ko priority do, phir power aur water distribute karo. Resources negative nahi ho sakte. End mein unresolved shortages report karo.

#include <iostream>
using namespace std;

int main() {
    int medical = 30;
    int power = 50;
    int water = 40;

    int medicalDemand1 = 12;
    int medicalDemand2 = 10;
    int medicalDemand3 = 15;

    int powerDemand1 = 20;
    int powerDemand2 = 15;
    int powerDemand3 = 25;

    int waterDemand1 = 10;
    int waterDemand2 = 12;
    int waterDemand3 = 15;

    int medicalGiven1 = 0, medicalGiven2 = 0, medicalGiven3 = 0;
    int powerGiven1 = 0, powerGiven2 = 0, powerGiven3 = 0;
    int waterGiven1 = 0, waterGiven2 = 0, waterGiven3 = 0;

    // Allocate medical supplies first
    if (medical >= medicalDemand1) {
        medicalGiven1 = medicalDemand1;
        medical -= medicalGiven1;
    } else {
        medicalGiven1 = medical;
        medical = 0;
    }

    if (medical >= medicalDemand2) {
        medicalGiven2 = medicalDemand2;
        medical -= medicalGiven2;
    } else {
        medicalGiven2 = medical;
        medical = 0;
    }

    if (medical >= medicalDemand3) {
        medicalGiven3 = medicalDemand3;
        medical -= medicalGiven3;
    } else {
        medicalGiven3 = medical;
        medical = 0;
    }

    // Allocate power next
    if (power >= powerDemand1) {
        powerGiven1 = powerDemand1;
        power -= powerGiven1;
    } else {
        powerGiven1 = power;
        power = 0;
    }

    if (power >= powerDemand2) {
        powerGiven2 = powerDemand2;
        power -= powerGiven2;
    } else {
        powerGiven2 = power;
        power = 0;
    }

    if (power >= powerDemand3) {
        powerGiven3 = powerDemand3;
        power -= powerGiven3;
    } else {
        powerGiven3 = power;
        power = 0;
    }

    // Allocate water last
    if (water >= waterDemand1) {
        waterGiven1 = waterDemand1;
        water -= waterGiven1;
    } else {
        waterGiven1 = water;
        water = 0;
    }

    if (water >= waterDemand2) {
        waterGiven2 = waterDemand2;
        water -= waterGiven2;
    } else {
        waterGiven2 = water;
        water = 0;
    }

    if (water >= waterDemand3) {
        waterGiven3 = waterDemand3;
        water -= waterGiven3;
    } else {
        waterGiven3 = water;
        water = 0;
    }

    cout << "Zone 1 received:\n";
    cout << "Medical: " << medicalGiven1
         << ", Power: " << powerGiven1
         << ", Water: " << waterGiven1 << "\n";

    cout << "Zone 2 received:\n";
    cout << "Medical: " << medicalGiven2
         << ", Power: " << powerGiven2
         << ", Water: " << waterGiven2 << "\n";

    cout << "Zone 3 received:\n";
    cout << "Medical: " << medicalGiven3
         << ", Power: " << powerGiven3
         << ", Water: " << waterGiven3 << "\n";

    // Calculate total shortage across all zones
    int medicalShortage =
        medicalDemand1 + medicalDemand2 + medicalDemand3
        - medicalGiven1 - medicalGiven2 - medicalGiven3;

    int powerShortage =
        powerDemand1 + powerDemand2 + powerDemand3
        - powerGiven1 - powerGiven2 - powerGiven3;

    int waterShortage =
        waterDemand1 + waterDemand2 + waterDemand3
        - waterGiven1 - waterGiven2 - waterGiven3;

    cout << "\nUnresolved shortages:\n";
    cout << "Medical: " << medicalShortage << "\n";
    cout << "Power: " << powerShortage << "\n";
    cout << "Water: " << waterShortage << "\n";

    cout << "\nRemaining resources:\n";
    cout << "Medical: " << medical << "\n";
    cout << "Power: " << power << "\n";
    cout << "Water: " << water << "\n";

    if (medicalShortage == 0 &&
        powerShortage == 0 &&
        waterShortage == 0) {
        cout << "All demands fulfilled\n";
    } else {
        cout << "Crisis remains unresolved\n";
    }

    return 0;
}

// Important logic:
// - Medical supplies first, power second aur water third allocate hote hain.
// - Har resource ka balance separately track hota hai.
// - Shortage = total demand − total allocated.
// - Agar kisi resource ki demand poori nahi hoti, crisis unresolved report hoti hai.
// - Yeh one-round educational simulation hai. Real city resource management mein medical urgency, minimum safe thresholds aur multiple recovery rounds bhi chahiye.
