// Q13. Mobile Data Usage
// A user has a monthly data limit of 10 GB. Write a C++ program using a while loop to continuously accept daily data usage. 
// Stop when the user enters -1 or when the total usage reaches 10 GB. 
// Display total data used and whether the data limit was reached.
// logic:
// User ke paas 10 GB ka monthly data limit hai. User daily data usage input karega. 
// Agar user -1 enter karta hai ya total usage 10 GB tak pahunchta hai, program stop ho jayega. End me total data used aur data limit reach hua ya nahi ye print karna hai.

// Solution:
#include <iostream>
using namespace std;

int main()
{
    double usage;                  // [INPUT] Aaj kitna data use hua
    double total = 0;              // [ACCUMULATOR] Total data usage
    double limit = 10;             // [LIMIT] Maximum 10 GB

    cout << "Enter daily data usage (-1 to stop): ";
    cin >> usage;

    while (usage != -1 && total < limit)  // [CONDITION]
    {
        total = total + usage;             // [WORK] Usage ko total me add karo

        cout << "Total used = " << total << " GB\n";

        if (total >= limit)                // [CHECK] 10 GB reach hua?
        {
            cout << "Data limit reached!\n";
            break;                         // [STOP] Loop end
        }

        cout << "Enter next day's usage (-1 to stop): ";
        cin >> usage;                      // [UPDATE] Next input
    }

    cout << "\nFinal Data Used = " << total << " GB";

    return 0;
}