// Level 51 — Complex real-world logic
// 1. Earthquake Early Warning Analysis
// Problem: A monitoring centre receives earthquake sensor readings from different locations. Each reading contains a magnitude value. Classify readings as:
// - Below 3: Low
// - 3–4.9: Moderate
// - 5–6.9: Strong
// - 7 or above: Severe
// Calculate the number of readings in each category and identify the strongest reading.
#include <iostream>
using namespace std;

int main()
{
    int n;
    int low = 0, moderate = 0;
    int strong = 0, severe = 0;
    double magnitude, highest = -1;

    cout << "Enter sensor readings: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Enter magnitude: ";
        cin >> magnitude;

        if (magnitude < 3)
            low++;
        else if (magnitude < 5)
            moderate++;
        else if (magnitude < 7)
            strong++;
        else
            severe++;

        if (magnitude > highest)
            highest = magnitude;
    }

    cout << "\nLow: " << low;
    cout << "\nModerate: " << moderate;
    cout << "\nStrong: " << strong;
    cout << "\nSevere: " << severe;
    cout << "\nHighest magnitude: " << highest;

    return 0;
}