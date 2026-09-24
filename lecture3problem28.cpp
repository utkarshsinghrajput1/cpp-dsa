// 28. Countdown Launch Timer
// Problem: Rocket launch ke liye 10 se 0 tak countdown print karo.
#include <iostream>
using namespace std;
int main() {
    int timer = 10;
    while (timer >= 0) {
        cout << "T-Minus: " << timer << " seconds" << endl;
        timer--;
    }
    cout << "Liftoff! 🚀" << endl;
    return 0;
}