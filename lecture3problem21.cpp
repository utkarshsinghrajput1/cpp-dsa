// 21. Phone Battery Drain
// Problem: Ek phone ki battery 100% hai aur har ghante game khelne par 15% battery khatam hoti hai. 
// While loop ka use karke tab tak simulate karo jab tak battery 0% ya usse kam na ho jaye.
#include <iostream>
using namespace std;
int main() {
    int battery = 100;
    int hours = 0;
    while (battery > 0) {
        hours++;
        battery -= 15;
        if(battery < 0) battery = 0; // Negative na ho
        cout << "Hour " << hours << " -> Battery left: " << battery << "%" << endl;
    }
    return 0;
}