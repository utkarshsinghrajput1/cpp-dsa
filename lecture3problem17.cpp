// Q17. Restaurant Ordering System
// Write a C++ program using a while loop to create a restaurant ordering system. 
// The menu contains Pizza ₹250, Burger ₹120, Pasta ₹180, and Coffee ₹80. 
// Allow the user to order multiple items. The program should continue until the user selects 0 to generate the bill. 
// Display the total number of items and total bill amount.
  
// Logic:
// START
//   ↓
// Initialize:
// totalItems = 0
// totalBill = 0
//   ↓
// Show Menu
//   ↓
// Take Choice
//   ↓
// Is choice = 0?
//   ├── YES → Print Total Items & Total Bill → STOP
//   │
//   └── NO
//        ↓
//    Is choice = 1?
//    ├── YES → totalBill += 250
//    │          totalItems++
//    │
//    └── NO → Is choice = 2?
//              ├── YES → totalBill += 120
//              │          totalItems++
//              │
//              └── NO → Is choice = 3?
//                        ├── YES → totalBill += 180
//                        │          totalItems++
//                        │
//                        └── NO → Is choice = 4?
//                                  ├── YES → totalBill += 80
//                                  │          totalItems++
//                                  │
//                                  └── NO → Print "Invalid Choice"
//                                           ↓
//                                   Go back to Show Menu
//        ↓
//    Go back to Show Menu
// Short mein yaad rakh:
// START
//  ↓
// Initialize totalItems & totalBill
//  ↓
// Show Menu
//  ↓
// Input Choice
//  ↓
// 0? ──YES──> Final Bill → STOP
//  ↓ NO
// Check Item
//  ↓
// Add Price + Increase Item Count
//  ↓
// Show Menu Again

// Solution:
#include <iostream>
using namespace std;

int main()
{
    int choice = -1;          // [INPUT] User ki choice
    int totalItems = 0;       // [COUNTER] Total items count
    int totalBill = 0;        // [ACCUMULATOR] Total bill

    while (choice != 0)       // [CONDITION] 0 tak ordering chalegi
    {
        cout << "\n===== RESTAURANT MENU =====\n";
        cout << "1. Pizza  - Rs. 250\n";
        cout << "2. Burger - Rs. 120\n";
        cout << "3. Pasta  - Rs. 180\n";
        cout << "4. Coffee - Rs. 80\n";
        cout << "0. Generate Bill\n";

        cout << "Enter your choice: ";
        cin >> choice;        // [INPUT] Choice lena

        if (choice == 1)
        {
            totalBill = totalBill + 250;   // [WORK] Pizza ka price add
            totalItems++;                  // [UPDATE] Item count +1
            cout << "Pizza added!\n";
        }
        else if (choice == 2)
        {
            totalBill = totalBill + 120;   // [WORK] Burger ka price add
            totalItems++;                  // [UPDATE] Item count +1
            cout << "Burger added!\n";
        }
        else if (choice == 3)
        {
            totalBill = totalBill + 180;   // [WORK] Pasta ka price add
            totalItems++;                  // [UPDATE] Item count +1
            cout << "Pasta added!\n";
        }
        else if (choice == 4)
        {
            totalBill = totalBill + 80;    // [WORK] Coffee ka price add
            totalItems++;                  // [UPDATE] Item count +1
            cout << "Coffee added!\n";
        }
        else if (choice == 0)
        {
            break;                         // [STOP] Bill generate karo
        }
        else
        {
            cout << "Invalid choice! Try again.\n";
        }
    }

    // [OUTPUT] Final Bill
    cout << "\n===== FINAL BILL =====\n";
    cout << "Total Items = " << totalItems << endl;
    cout << "Total Bill = Rs. " << totalBill << endl;

    return 0;
}