// 31. Data Center Server Temperature Monitor
// Problem: N servers ke temperatures input lo. 70°C se upar warning, 85°C se upar critical alert, otherwise normal status print karo. Har category ka count calculate karo.
#include <iostream>
using namespace std;

int main() {
    int N, temperature;
    int normal = 0, warning = 0, critical = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> temperature;

        if (temperature > 85) {
            critical++;
            cout << "CRITICAL" << endl;
        } else if (temperature > 70) {
            warning++;
            cout << "WARNING" << endl;
        } else {
            normal++;
            cout << "NORMAL" << endl;
        }
    }

    cout << "Normal: " << normal << endl;
    cout << "Warning: " << warning << endl;
    cout << "Critical: " << critical;

    return 0;
}