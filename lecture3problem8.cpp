// Q.Guess the number

// Computer ke paas ek fixed number 37 hai. User guesses karta rahe jab tak correct answer na mile.
// Solution: Below is a C++ program that allows the user to guess a fixed number (37) until they guess it correctly.
#include <iostream>
using namespace std;

int main()
{
    int guess;                         // [VARIABLE] User ka guess
    int secret = 37;                   // [TARGET] Correct number

    cout << "Guess the number: ";
    cin >> guess;

    while (guess != secret)            // [CONDITION] Jab tak guess wrong hai
    {
        cout << "Wrong! Try again: ";
        cin >> guess;                  // [INPUT] New guess
    }

    cout << "Correct! You won.";       // [OUTPUT]

    return 0;
}