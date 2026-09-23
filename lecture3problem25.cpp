// 25. Bacteria Colony Growth
// Problem: Lab me ek bacteria ki colony shuru me 100 cells se start hoti hai aur har ghante double ho jati hai. 
// 1,000 cells tak pahunchne me kitne ghante lagenge?
#include <iostream>
using namespace std;
int main() {
    int bacteria = 100;
    int target = 1000;
    int hours = 0;
    while (bacteria < target) {
        hours++;
        bacteria *= 2; // Double ho raha hai
        cout << "Hour " << hours << " -> Bacteria count: " << bacteria << endl;
    }
    return 0;
}