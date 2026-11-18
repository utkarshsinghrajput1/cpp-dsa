// 32. Internet Data Usage Controller
// Problem: User ke paas D GB monthly data hai. Daily usage input lo. Jab remaining data 10% se kam ho jaye toh low-data warning print karo. Data finish hone ke baad additional usage count karo.
#include <iostream>
using namespace std;

int main() {
    double D, usage, remaining;
    int days, extraDays = 0;

    cin >> D >> days;
    remaining = D;

    for (int i = 1; i <= days; i++) {
        cin >> usage;

        if (usage <= remaining) {
            remaining = remaining - usage;
        } else {
            extraDays++;
            remaining = 0;
        }

        cout << "Day " << i
             << " Remaining: " << remaining << endl;

        if (remaining > 0 && remaining < D * 0.10)
            cout << "LOW DATA WARNING" << endl;
    }

    cout << "Days with excess usage: " << extraDays;

    return 0;
}