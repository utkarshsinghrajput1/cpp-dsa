// To convert a decimal number into binary 
#include <iostream>
using namespace std;

int main() {
    int decimal, binary = 0, i = 1;
    cout << "Enter a decimal number: ";
    cin >> decimal;
    while (decimal != 0) {
        binary += (decimal % 2) * i;
        decimal /= 2;
        i *= 10;
    }
    cout << "The binary equivalent is: " << binary << endl;
    return 0;
}

// Second method, proper method to convert decimal to binary
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal;

    if (decimal == 0) {
        cout << "The binary equivalent is: 0" << endl;
        return 0;
    }

    string binary = "";
    while (decimal > 0) {
        int rem = decimal % 2;
        binary += to_string(rem); // Remainder ko string me add karte jao
        decimal /= 2;
    }

    reverse(binary.begin(), binary.end()); // Ulta karke correct order banao
    cout << "The binary equivalent is: " << binary << endl;
    return 0;
}

// Third method using Bitwise operators
// fastest method to convert decimal to binary
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;

    cout << "The binary equivalent is: ";
    bool leading_zero = true;
    
    // 31th bit se lekar 0th bit tak check karo (32-bit integer ke liye)
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1) {
            cout << 1;
            leading_zero = false;
        } else if (!leading_zero) {
            cout << 0;
        }
    }
    
    if (leading_zero) cout << 0; // Agar number khud 0 ho
    cout << endl;
    return 0;
}