// 12. The Reverse-and-Multiply Puzzle
// Very Hard
// Question: Ek positive number N diya hai. Uska reverse nikalo. Phir original aur reversed number ka difference calculate karo. Difference ko reverse karo aur check karo ki dono equal hain ya nahi.
// Example: N = 123
// Reverse = 321
// Difference = 321 - 123 = 198
// Reverse of difference = 891

// Output:
// Difference = 198
// Reversed difference = 891
// Not equal


#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long temp = n;
    long long reversed = 0;

    // Original number reverse karo
    while (temp > 0) {
        int digit = temp % 10;
        reversed = reversed * 10 + digit;
        temp = temp / 10;
    }

    // Difference negative na ho, isliye larger minus smaller
    long long difference;

    if (n > reversed) {
        difference = n - reversed;
    } else {
        difference = reversed - n;
    }

    // Difference ko reverse karo
    temp = difference;
    long long reverseDifference = 0;

    while (temp > 0) {
        int digit = temp % 10;
        reverseDifference = reverseDifference * 10 + digit;
        temp = temp / 10;
    }

    cout << "Difference = " << difference << endl;
    cout << "Reversed difference = " << reverseDifference << endl;

    if (difference == reverseDifference) {
        cout << "Equal";
    } else {
        cout << "Not equal";
    }

    return 0;
}


// Challenge: Aise numbers search karo jinke difference ka reverse uske equal ho. Pehle manually pattern discover karne ki koshish kar.

