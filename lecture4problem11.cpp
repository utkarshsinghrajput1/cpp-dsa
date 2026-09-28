// Q. Leap Year 
// Ye thoda logical question hai.
// Logic:
// Year leap year hota hai agar:
// year % 400 == 0
// OR agar dusri condition lagani he
// year % 4 == 0 AND year % 100 != 0
#include <iostream>
using namespace std;

int main() {
    int year;

    cout << "Enter year: ";
    cin >> year;

    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        cout << "Leap Year";
    }
    else {
        cout << "Not a Leap Year";
    }

    return 0;
}