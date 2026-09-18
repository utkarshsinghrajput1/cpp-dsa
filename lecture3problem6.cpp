// Q1. Number me kitne 0 hain? 

// Input: 1050200
// Output: 4

// Solution: Below is a C++ program that counts the number of zeros in an integer input by the user.
#include <iostream>
using namespace std;

int main()
{
    int n;                         // [INPUT] Number store karega
    int count = 0;                 // [COUNTER] Zero count karega

    cout << "Enter number: ";
    cin >> n;

    while (n > 0)                  // [LOOP] Jab tak number khatam nahi hota
    {
        int digit = n % 10;        // [DIGIT] Last digit nikalo

        if (digit == 0)             // [CHECK] Kya digit 0 hai?
        {
            count++;               // [UPDATE] Zero ki count increase
        }

        n = n / 10;                // [REMOVE] Last digit remove karo
    }

    cout << "Number of zeros = " << count;

    return 0;
}