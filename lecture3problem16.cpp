// 🌡️ Problem: Temperature Monitor

// Ek program banao jo repeatedly temperature input le.

// Rules:
// Temperature 0°C se kam ho → "Very Cold" print karo.
// Temperature 0°C se 20°C ke beech ho → "Cold" print karo.
// Temperature 20°C se 35°C ke beech ho → "Normal" print karo.
// Temperature 35°C se zyada ho → "Hot" print karo.
// User jab -999 enter kare, program stop ho jaye.
// End mein total temperatures kitne enter kiye gaye wo print karo. -999 ko count nahi karna hai.
// Example :
// Enter temperature: 15
// Cold

// Enter temperature: 28
// Normal

// Enter temperature: 40
// Hot

// Enter temperature: -5
// Very Cold

// Enter temperature: -999

// Total temperatures = 4

// Like isme naya kya he ye dekh 
// Isme naya kya hai?

// Is question mein tu seekhega:

// Sentinel value → -999
// while loop
// Multiple conditions → if / else if / else
// Counter → valid temperatures count karna
// Important: -999 ko count nahi karna

// Solution:
#include <iostream>
using namespace std;

int main()
{
    double temperature;       // [INPUT] Temperature store karega
    int count = 0;            // [COUNTER] Valid temperatures count karega

    cout << "Enter temperature (-999 to stop): ";
    cin >> temperature;       // [INPUT] First temperature

    while (temperature != -999)   // [CONDITION] -999 tak loop chalega
    {
        count++;                  // [UPDATE] Temperature count increase

        // [CHECK] Temperature kis range mein hai?
        if (temperature < 0)
        {
            cout << "Very Cold\n";
        }
        else if (temperature <= 20)
        {
            cout << "Cold\n";
        }
        else if (temperature <= 35)
        {
            cout << "Normal\n";
        }
        else
        {
            cout << "Hot\n";
        }

        // [INPUT] Next temperature
        cout << "Enter temperature (-999 to stop): ";
        cin >> temperature;
    }

    // [OUTPUT] Total valid temperatures
    cout << "\nTotal temperatures = " << count << endl;

    return 0;
}
