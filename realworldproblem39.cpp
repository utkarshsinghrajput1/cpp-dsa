// Problem 39: Multi-Resource Construction Project Scheduler
// Question: Construction project mein 3 tasks hain. Task 2, Task 1 ke baad hi start ho sakta hai; Task 3, Task 2 ke baad start hoga. Har task ki duration alag hai. while loop se project completion simulate karo.


#include <iostream>
using namespace std;

int main() {
    int duration1 = 2;
    int duration2 = 3;
    int duration3 = 2;

    int remaining1 = duration1;
    int remaining2 = duration2;
    int remaining3 = duration3;

    int task1Done = 0;
    int task2Done = 0;
    int task3Done = 0;

    int time = 0;

    while (task3Done == 0) {
        // Task 1 can start immediately
        if (task1Done == 0) {
            remaining1--;

            if (remaining1 == 0) {
                task1Done = 1;
                cout << "Task 1 completed at time " << time + 1 << "\n";
            }
        }

        // Task 2 starts only after Task 1 completes
        else if (task2Done == 0) {
            remaining2--;

            if (remaining2 == 0) {
                task2Done = 1;
                cout << "Task 2 completed at time " << time + 1 << "\n";
            }
        }

        // Task 3 starts only after Task 2 completes
        else if (task3Done == 0) {
            remaining3--;

            if (remaining3 == 0) {
                task3Done = 1;
                cout << "Task 3 completed at time " << time + 1 << "\n";
            }
        }

        time++;
    }

    cout << "Total project duration: " << time << " time units\n";

    return 0;
}


// Important logic:
// - Task completion flags dependency ko maintain karte hain.
// - Task 2, Task 1 complete hone se pehle execute nahi hota.
// - Task 3 bhi Task 2 ke baad hi start hota hai.
// - Yeh sequential dependency model hai; workers, machines aur parallel tasks include nahi hain.