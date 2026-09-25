// 33. Parking Lot Full Checker
// Problem: Ek parking lot ki maximum capacity 5 cars ki hai. 
// Ek-ek karke cars enter kar rahi hain. 
// Lot full hone par message print karo.
#include <iostream>
using namespace std;
int main() {
    int capacity = 5;
    int cars_parked = 0;
    while (cars_parked < capacity) {
        cars_parked++;
        cout << "Car entered. Total parked: " << cars_parked << "/" << capacity << endl;
    }
    cout << "Parking Full! Gate closed." << endl;
    return 0;
}