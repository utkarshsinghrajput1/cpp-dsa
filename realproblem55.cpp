// 55. Museum Visitor Flow and Capacity Control
// Problem: A museum has several exhibition halls. Visitors enter and leave each hall throughout the day.

// For each hall, process a sequence of entry and exit events. Calculate the maximum simultaneous occupancy and determine whether the hall's capacity was exceeded.
#include <iostream>
using namespace std;

int main()
{
    int halls, events, capacity;
    int overcrowded = 0;

    cout << "Enter halls: ";
    cin >> halls;

    cout << "Enter events per hall: ";
    cin >> events;

    cout << "Enter hall capacity: ";
    cin >> capacity;

    for (int h = 1; h <= halls; h++)
    {
        int visitors = 0;
        int maximum = 0;
        int invalidExits = 0;

        for (int e = 1; e <= events; e++)
        {
            int type;

            cout << "1 Entry, 2 Exit: ";
            cin >> type;

            if (type == 1)
                visitors++;
            else if (type == 2)
            {
                if (visitors > 0)
                    visitors--;
                else
                    invalidExits++;
            }

            if (visitors > maximum)
                maximum = visitors;
        }

        cout << "\nHall " << h;
        cout << "\nMaximum occupancy: " << maximum;
        cout << "\nInvalid exits: " << invalidExits;

        if (maximum > capacity)
        {
            overcrowded++;
            cout << "\nCapacity exceeded.";
        }
        else
            cout << "\nCapacity maintained.";
    }

    cout << "\nOvercrowded halls: " << overcrowded;

    return 0;
}