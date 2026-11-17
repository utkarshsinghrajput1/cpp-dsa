// 28. Emergency Ambulance Dispatch
// Problem: N emergency calls ki severity input lo: 1 = low, 2 = medium, 3 = high. Har high-severity call par 3 dispatch points assign karo, medium par 2, low par 1. Total dispatch points calculate karo.
#include <iostream>
using namespace std;

int main() {
    int N, severity;
    int points = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> severity;

        if (severity == 1)
            points = points + 1;
        else if (severity == 2)
            points = points + 2;
        else if (severity == 3)
            points = points + 3;
        else
            cout << "Invalid Severity" << endl;
    }

    cout << "Total Dispatch Points: " << points;
    return 0;
}