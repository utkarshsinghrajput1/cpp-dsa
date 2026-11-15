// 19. Road Construction Material Estimator
// Problem: Road ki length aur width input lo. Ek square metre ke liye 0.05 cubic metre material chahiye. Total material calculate karo. Material bags ki capacity 0.5 cubic metre hai. Required bags count karo.
#include <iostream>
using namespace std;

int main() {
    double length, width;
    cin >> length >> width;

    double material = length * width * 0.05;
    int bags = 0;
    double supplied = 0;

    while (supplied < material) {
        supplied = supplied + 0.5;
        bags++;
    }

    cout << "Material Required: " << material << endl;
    cout << "Bags Required: " << bags;

    return 0;
}