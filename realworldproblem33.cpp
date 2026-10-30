// Problem 33: EV Battery Swap Station Scheduler
// Question: EV station par 3 charged batteries hain, jinmein 40%, 70% aur 90% charge hai. Har vehicle ko required minimum charge chahiye. Vehicle ko sabse kam sufficient charge wali available battery do, taaki high-charge batteries unnecessary use na hon.

#include <iostream>
using namespace std;

int main() {
    int battery1 = 40;
    int battery2 = 70;
    int battery3 = 90;

    int available1 = 1;
    int available2 = 1;
    int available3 = 1;

    int vehicles;
    int waiting = 0;

    cout << "Enter number of vehicles: ";
    cin >> vehicles;

    for (int i = 1; i <= vehicles; i++) {
        int required;
        cout << "Enter minimum required charge: ";
        cin >> required;

        if (required <= 0 || required > 100) {
            cout << "Invalid charge requirement\n";
            waiting++;
        }
        // Choose the lowest sufficient available battery
        else if (available1 && battery1 >= required) {
            available1 = 0;
            cout << "Vehicle " << i << " receives 40% battery\n";
        }
        else if (available2 && battery2 >= required) {
            available2 = 0;
            cout << "Vehicle " << i << " receives 70% battery\n";
        }
        else if (available3 && battery3 >= required) {
            available3 = 0;
            cout << "Vehicle " << i << " receives 90% battery\n";
        }
        else {
            waiting++;
            cout << "Vehicle " << i << " added to waiting list\n";
        }
    }

    cout << "\nAvailable batteries:\n";
    cout << "40% battery: " << available1 << "\n";
    cout << "70% battery: " << available2 << "\n";
    cout << "90% battery: " << available3 << "\n";
    cout << "Vehicles waiting: " << waiting << "\n";

    return 0;
}

// Important logic:
// - Batteries ascending charge order mein check hoti hain.
// - available flag batata hai ki battery abhi unused hai ya nahi.
// - Har battery maximum ek vehicle ko assign hoti hai.
// - Is simplified version mein batteries recharge hokar automatically available nahi hoti.