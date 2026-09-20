// Fuel Tank
// Question: Tank ki capacity 50 litres hai. User fuel add karta rahe. Jab tank full ho jaye to program stop karo.
// Solution:
#include <iostream>
using namespace std;

int main()
{
    int fuel = 0;                         // [VARIABLE] Current fuel
    int add;                              // [INPUT] Fuel to add
    const int capacity = 50;              // [CONSTANT] Tank capacity

    while (fuel < capacity)               // [LOOP] Tank full hone tak
    {
        cout << "Enter fuel to add: ";
        cin >> add;

        if (fuel + add > capacity)        // [CHECK] Capacity exceed?
        {
            cout << "Cannot add! Tank capacity exceeded.\n";
        }
        else
        {
            fuel = fuel + add;            // [UPDATE] Fuel increase
            cout << "Current Fuel = " << fuel << " L\n";
        }
    }

    cout << "Tank Full!";

    return 0;
}