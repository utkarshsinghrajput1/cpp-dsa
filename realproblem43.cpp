// 43. Construction Project Deadline Monitor
// Problem: Construction project ke N tasks hain. Har task ka estimated duration aur actual duration input lo. Agar actual duration estimated duration se zyada hai toh delay calculate karo. Total project delay calculate karo.
#include <iostream>
using namespace std;

int main() {
    int N, estimated, actual;
    int totalDelay = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> estimated >> actual;

        if (actual > estimated) {
            int delay = actual - estimated;
            totalDelay = totalDelay + delay;

            cout << "Task " << i
                 << " Delayed: " << delay << " days" << endl;
        } else {
            cout << "Task " << i << ": ON TIME" << endl;
        }
    }

    cout << "Total Project Delay: " << totalDelay << " days";

    return 0;
}