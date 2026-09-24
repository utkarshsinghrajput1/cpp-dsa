// 29. Machine Overheat Warning
// Problem: Ek industrial machine ka normal temperature 30°C hai. 
// Har minute machine chalne par temperature 8°C badhta hai. 
// Agar temperature 80°C se upar ho jaye toh emergency shutdown trigger karo.
#include <iostream>
using namespace std;
int main() {
    int temp = 30;
    int minute = 0;
    while (temp < 80) {
        minute++;
        temp += 8;
        cout << "Minute " << minute << " -> Temperature: " << temp << "C" << endl;
    }
    cout << "⚠️ Emergency Shutdown! Machine overheated." << endl;
    return 0;
}