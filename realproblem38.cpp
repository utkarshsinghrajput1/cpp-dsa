// 38. Air Pollution Monitoring System
// Problem: N monitoring stations se pollution readings input lo. Reading 50 tak safe, 51–100 moderate, 100 se upar high pollution hai. Har category ke stations count karo.
#include <iostream>
using namespace std;

int main() {
    int N, reading;
    int safe = 0, moderate = 0, high = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> reading;

        if (reading <= 50) {
            safe++;
            cout << "SAFE" << endl;
        } else if (reading <= 100) {
            moderate++;
            cout << "MODERATE" << endl;
        } else {
            high++;
            cout << "HIGH POLLUTION" << endl;
        }
    }

    cout << "Safe Stations: " << safe << endl;
    cout << "Moderate Stations: " << moderate << endl;
    cout << "High Pollution Stations: " << high;

    return 0;
}