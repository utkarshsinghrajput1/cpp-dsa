// 24. Blood Bank Inventory Monitor
// Problem: Blood bank mein 4 blood groups ke available units input lo. Har group ke liye minimum required stock bhi input lo. Stock minimum se kam hone par shortage alert print karo.
#include <iostream>
using namespace std;

int main() {
    int stock, minimum;
    int shortageGroups = 0;

    for (int group = 1; group <= 4; group++) {
        cin >> stock >> minimum;

        cout << "Blood Group " << group << ": ";

        if (stock < minimum) {
            cout << "SHORTAGE" << endl;
            shortageGroups++;
        } else {
            cout << "SUFFICIENT" << endl;
        }
    }

    cout << "Groups with shortage: " << shortageGroups;
    return 0;
}