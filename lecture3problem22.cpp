// 22. Car Fuel Consumption
// Problem: Ek car ke fuel tank me 50 liters petrol hai. 
// Har 10 km chalne par 5 liters petrol consume hota hai. 
// 100 km ki yatra me fuel ki sthiti track karo.
#include <iostream>
using namespace std;
int main() {
    int fuel = 50;
    int distance = 0;
    while (fuel >= 5 && distance < 100) {
        distance += 10;
        fuel -= 5;
        cout << "Distance: " << distance << " km, Fuel left: " << fuel << " L" << endl;
    }
    return 0;
}