// Q15. Parking System
// Write a C++ program using a while loop to manage a parking lot with a capacity of 10 vehicles. 
// Allow the user to enter 1 for vehicle entry, 2 for vehicle exit, and 0 to close the system. 
// Do not allow entry when the parking lot is full and do not allow exit when there are no vehicles. 
// Display the current number of vehicles after every operation.

// Flow:

// Menu dikhao → choice lo → operation perform karo → result dikhao → menu dobara dikhao → Exit par stop

// Step-by-step 

// 1. Menu baar-baar dikhana hai:
// while (choice != 5)

// Yahan maan lete hain:
// [1 → Addition
// 2 → Subtraction
// 3 → Multiplication
// 4 → Division
// 5 → Exit]

// 2. User ki choice input lo.

// 3. if-else se check karo ki user ne kya choose kiya.

// 4. Calculation karo.

// 5. Choice 5 hui to loop stop.

// Solution:
#include <iostream>
using namespace std;

int main()
{
    int choice;              // [INPUT] User ki choice
    double num1, num2;       // [INPUT] Do numbers

    while (choice != 5)      // [CONDITION] Exit nahi hua tab tak loop
    {
        // [MENU] Options show karna
        cout << "\n===== CALCULATOR =====\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;       // [INPUT] Choice lena

        // [STOP] Agar user Exit choose kare
        if (choice == 5)
        {
            cout << "Calculator closed!";
            break;
        }

        // [INPUT] Numbers lena
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        // [WORK] Choice ke according operation
        if (choice == 1)
        {
            cout << "Result = " << num1 + num2;
        }
        else if (choice == 2)
        {
            cout << "Result = " << num1 - num2;
        }
        else if (choice == 3)
        {
            cout << "Result = " << num1 * num2;
        }
        else if (choice == 4)
        {
            if (num2 != 0)       // [CHECK] 0 se divide nahi kar sakte
                cout << "Result = " << num1 / num2;
            else
                cout << "Cannot divide by zero!";
        }
        else
        {
            cout << "Invalid choice!";
        }
    }

    return 0;
}