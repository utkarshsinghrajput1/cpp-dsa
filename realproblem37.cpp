// 37. Rainwater Harvesting Calculator
// Problem: N days ki rainfall in millimetres input lo. Roof area aur collection efficiency percentage input lo. Total collected water litres mein calculate karo. (1 mm rainfall on 1 square metre = 1 litre.)
#include <iostream>
using namespace std;

int main() {
    int N;
    double area, efficiency, rain;
    double totalRain = 0;

    cin >> area >> efficiency >> N;

    for (int i = 1; i <= N; i++) {
        cin >> rain;

        if (rain >= 0)
            totalRain = totalRain + rain;
    }

    double water = totalRain * area * efficiency / 100;

    cout << "Total Rainfall: " << totalRain << " mm" << endl;
    cout << "Collected Water: " << water << " litres";

    return 0;
}