// 36. Marathon Hydration Station
// Problem: Ek runner 42 km ki marathon daud raha hai. 
// Wo har 5 km par ek paani ka break leta hai. 
// 42 km tak breaks track karo.
#include <iostream>
using namespace std;
int main() {
    int distance = 0;
    int finish = 42;
    int break_count = 0;
    while (distance < finish) {
        distance += 5;
        if(distance > finish) distance = finish;
        break_count++;
        cout << "Water break " << break_count << " at " << distance << " km mark." << endl;
    }
    return 0;
}