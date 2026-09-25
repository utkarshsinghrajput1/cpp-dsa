// 34. Radio Frequency Tuner
// Problem: Ek radio frequency 88.0 MHz se start hoti hai aur clear station milne tak 0.5 MHz badhti hai jab tak wo 98.3 MHz (Target station) par na pahunch jaye.
#include <iostream>
using namespace std;
int main() {
    float freq = 88.0;
    float target = 98.3;
    while (freq < target) {
        cout << "Scanning frequency: " << freq << " MHz" << endl;
        freq += 0.5;
    }
    cout << "Target Station 98.3 MHz Connected!" << endl;
    return 0;
}