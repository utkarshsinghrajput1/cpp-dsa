// 53. Port Container Weight Balance Analyzer
// Problem: A cargo ship has several sections. Every section contains a number of containers. Each container has a different weight.

// Calculate:
// - Total weight per section.
// - Average container weight per section.
// - Heaviest section.
// - Whether the ship exceeds its total weight limit.
#include <iostream>    
using namespace std;

int main()
{
    int sections, containers;
    double shipLimit;

    double totalShipWeight = 0;
    double heaviestSection = 0;

    cout << "Enter sections: ";
    cin >> sections;

    cout << "Containers per section: ";
    cin >> containers;

    cout << "Ship weight limit: ";
    cin >> shipLimit;

    for (int i = 1; i <= sections; i++)
    {
        double sectionWeight = 0;

        for (int j = 1; j <= containers; j++)
        {
            double weight;

            cout << "Container weight: ";
            cin >> weight;

            sectionWeight += weight;
        }

        totalShipWeight += sectionWeight;

        if (sectionWeight > heaviestSection)
            heaviestSection = sectionWeight;

        cout << "Section weight: " << sectionWeight;
        cout << "\nSection average: "
             << sectionWeight / containers << endl;
    }

    cout << "\nTotal ship weight: " << totalShipWeight;
    cout << "\nHeaviest section: " << heaviestSection;

    if (totalShipWeight > shipLimit)
        cout << "\nShip exceeds weight limit.";
    else
        cout << "\nShip is within weight limit.";

    return 0;
}