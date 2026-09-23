// 24. Fitness Step Tracker
// Problem: Ek user ka daily goal 10,000 steps chalna hai. 
// Wo har walk session me 1,200 steps chalta hai. 
// Jab tak goal complete na ho, sessions count karo.
#include <iostream>
using namespace std;
int main() {
    int steps = 0;
    int goal = 10000;
    int session_steps = 1200;
    int sessions = 0;
    while (steps < goal) {
        sessions++;
        steps += session_steps;
        cout << "Session " << sessions << " done. Total steps: " << steps << endl;
    }
    return 0;
}