// 20. Armstrong Number Check
// Problem Statement:
// Ek 3-digit ka number input lo aur check karo ki wo Armstrong number hai ya nahi. Armstrong number wo hota hai jiske saare digits ke cubes ka sum usi number ke barabar hota hai.
// Example: 153 = (1*1*1) + (5*5*5) + (3*3*3) = 1 + 125 + 27 = 153.

// solution:
#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "Enter a 3-digit number: ";
    cin >> n;
    
    int temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        sum += (digit * digit * digit); // Cube of digit
        temp /= 10;
    }
    
    if (sum == n) {
        cout << n << " is an Armstrong number." << endl;
    } else {
        cout << n << " is not an Armstrong number." << endl;
    }
    
    return 0;
}