// 34. Machine Maintenance Downtime
// Problem: Factory ki M machines hain. Har machine ka total working time aur downtime input lo. Availability percentage calculate karo. 90% se kam availability par maintenance required print karo.
#include <iostream>
using namespace std;

int main() {
    int M;
    double working, downtime;
    cin >> M;

    for (int i = 1; i <= M; i++) {
        cin >> working >> downtime;

        if (working <= 0 || downtime < 0) {
            cout << "Invalid Data" << endl;
        } else {
            double availability =
                working * 100.0 / (working + downtime);

            cout << "Machine " << i
                 << ": " << availability << "%" << endl;

            if (availability < 90)
                cout << "MAINTENANCE REQUIRED" << endl;
            else
                cout << "MACHINE NORMAL" << endl;
        }
    }

    return 0;
}