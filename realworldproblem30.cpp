// Problem 30: Emergency Shelter Capacity Planner
// Question: 3 shelters mein 10, 8 aur 6 logon ki capacity hai. Families ke sizes input lo. Family ko split kiye bina pehle Shelter 1, phir Shelter 2, phir Shelter 3 mein fit karne ki koshish karo. Capacity insufficient ho toh family ko unaccommodated mark karo.

#include <iostream>
using namespace std;

int main() {
    int cap1 = 10, cap2 = 8, cap3 = 6;
    int people1 = 0, people2 = 0, people3 = 0;

    int families;
    int unaccommodated = 0;

    cout << "Enter number of families: ";
    cin >> families;

    for (int i = 1; i <= families; i++) {
        int size;

        cout << "Enter family size: ";
        cin >> size;

        if (size <= 0) {
            cout << "Invalid family size\n";
            unaccommodated++;
        }
        // Keep each family together in one shelter
        else if (people1 + size <= cap1) {
            people1 += size;
            cout << "Family assigned to Shelter 1\n";
        }
        else if (people2 + size <= cap2) {
            people2 += size;
            cout << "Family assigned to Shelter 2\n";
        }
        else if (people3 + size <= cap3) {
            people3 += size;
            cout << "Family assigned to Shelter 3\n";
        }
        else {
            unaccommodated++;
            cout << "No shelter has enough space\n";
        }
    }

    cout << "\nShelter 1 occupancy: " << people1 << "/" << cap1 << "\n";
    cout << "Shelter 2 occupancy: " << people2 << "/" << cap2 << "\n";
    cout << "Shelter 3 occupancy: " << people3 << "/" << cap3 << "\n";
    cout << "Unaccommodated families: " << unaccommodated << "\n";

    return 0;
}


// Important logic:
// - Har family ek single shelter mein assign hoti hai.
// - Har allocation se pehle remaining capacity check hoti hai.
// - Agar koi shelter fit nahi kar sakta, family unaccommodated count hoti hai.
// - Yeh model supplies aur accessibility restrictions ko include nahi karta.
