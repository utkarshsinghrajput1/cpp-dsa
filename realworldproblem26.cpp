// Problem 26: Data Center Server Task Balancer
// Question: 3 servers ke current loads aur maximum capacities alag hain. Har task ka CPU demand diya gaya hai. Task ko eligible server par assign karo jiska current load sabse kam hai. Capacity cross nahi honi chahiye.

#include <iostream>
using namespace std;

int main() {
    int load1 = 30, load2 = 20, load3 = 40;
    int cap1 = 100, cap2 = 80, cap3 = 120;

    int tasks = 5;
    int rejected = 0;

    for (int i = 1; i <= tasks; i++) {
        int demand;
        cout << "Enter CPU demand for task " << i << ": ";
        cin >> demand;

        if (demand <= 0) {
            cout << "Invalid task demand\n";
            rejected++;
        }
        // Server 1 must have enough capacity and the lowest eligible load
        else if (load1 + demand <= cap1 &&
                 load1 <= load2 && load1 <= load3) {
            load1 += demand;
            cout << "Task assigned to Server 1\n";
        }
        else if (load2 + demand <= cap2 &&
                 load2 <= load3) {
            load2 += demand;
            cout << "Task assigned to Server 2\n";
        }
        else if (load3 + demand <= cap3) {
            load3 += demand;
            cout << "Task assigned to Server 3\n";
        }
        else {
            rejected++;
            cout << "No server has enough capacity\n";
        }
    }

    cout << "\nFinal server loads:\n";
    cout << "Server 1: " << load1 << "/" << cap1 << "\n";
    cout << "Server 2: " << load2 << "/" << cap2 << "\n";
    cout << "Server 3: " << load3 << "/" << cap3 << "\n";
    cout << "Unassigned tasks: " << rejected << "\n";

    return 0;
}

// Important logic:
// - Har task ka demand input hota hai.
// - Task assign karne se pehle capacity check hoti hai.
// - Eligible server ka load update hota hai.
// - Is fixed-priority comparison mein server selection strictly globally lowest eligible load ke hisaab se nahi hota agar Server 1 ineligible ho; yeh sequential simplified scheduler hai.
