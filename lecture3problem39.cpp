// 39. Alarm Snooze Limit
// Problem: Subah alarm bajne par user maximum 3 baar snooze kar sakta hai uske baad uthna hi padta hai. 
// Loop se snooze count track karo.
// Solution:
#include <iostream>
using namespace std;
int main() {
    int snoozes = 0;
    int max_snooze = 3;
    while (snoozes < max_snooze) {
        snoozes++;
        cout << "Alarm snoozed " << snoozes << " times. Sleeping more..." << endl;
    }
    cout << "Max snooze reached! Get out of bed now!" << endl;
    return 0;
}