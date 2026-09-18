// Q4. ATM PIN
// User ko maximum 3 attempts milenge.
// Solution:
#include <iostream>
using namespace std;

int main()
{
    int pin;                            // [INPUT] User PIN
    int correctPin = 1234;              // [TARGET] Correct PIN
    int attempts = 0;                  // [COUNTER]

    while (attempts < 3)               // [CONDITION] Maximum 3 attempts
    {
        cout << "Enter PIN: ";
        cin >> pin;

        if (pin == correctPin)          // [CHECK] PIN correct?
        {
            cout << "Access Granted!";
            break;                      // [STOP] Correct hone par exit
        }

        attempts++;                     // [UPDATE] Attempt increase
        cout << "Wrong PIN!\n";
    }

    if (attempts == 3 && pin != correctPin)
    {
        cout << "Account Locked!";
    }

    return 0;
}