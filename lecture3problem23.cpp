// 23. Water Tank Filling
// Problem: Ek khali tank ki capacity 100 liters hai. 
// Har baar bucket se 15 liters pani dala jata hai. 
// Jab tak tank full nahi hota, loop chalao.
#include <iostream>
using namespace std;
int main() {
    int current_water = 0;
    int capacity = 100;
    int bucket = 15;
    int attempts = 0;
    while (current_water < capacity) {
        attempts++;
        current_water += bucket;
        cout << "Bucket " << attempts << " dali. Total pani: " << current_water << " L" << endl;
    }
    return 0;
}