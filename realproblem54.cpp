// 54. International Parcel Customs Duty Calculator
// Problem: A customs office receives imported parcels. Every parcel has a declared value and a product category.

// Use these simplified rules:
// - Category 1: 5% duty.
// - Category 2: 12% duty.
// - Category 3: 20% duty.
// - Add a fixed processing fee of ₹100.
// Calculate the duty and final payable amount for every parcel and the total customs revenue.
#include <iostream>   
using namespace std;

int main()
{
    int parcels;
    double revenue = 0;

    cout << "Enter parcels: ";
    cin >> parcels;

    for (int i = 1; i <= parcels; i++)
    {
        int category;
        double value, rate;

        cout << "\nDeclared value: ";
        cin >> value;

        cout << "Category (1-3): ";
        cin >> category;

        if (category == 1)
            rate = 5;
        else if (category == 2)
            rate = 12;
        else if (category == 3)
            rate = 20;
        else
        {
            cout << "Invalid category.";
            continue;
        }

        double duty = value * rate / 100;
        double payable = value + duty + 100;

        revenue += duty + 100;

        cout << "Customs duty: " << duty;
        cout << "\nFinal payable: " << payable << endl;
    }

    cout << "\nTotal customs revenue: " << revenue;

    return 0;
}