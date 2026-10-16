// Question 14: Digit Collision Hunter
// Ek number N diya hai. Har digit ko check karo aur pata lagao ki kitne digits aise hain jo number mein exactly do baar aaye hain. Lekin digit ko count karne ke liye arrays ya strings use nahi karne.
// Example: N = 1223334455
// Output:
// Digit 1: 0 times? No
// Digits appearing exactly twice: 2
// Explanation: 2 do baar aur 4 do baar aata hai. 5 bhi do baar aata hai. Isliye correct output 3 hai.
// Concept: nested while loops, digit extraction, counting.
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n < 0)
        n = -n;

    int answer = 0;

    // Har digit ko target maan kar check karo
    for (int target = 0; target <= 9; target++) {
        long long temp = n;
        int count = 0;

        // Number ke har digit ko check karo
        while (temp > 0) {
            int digit = temp % 10;

            if (digit == target)
                count++;

            temp /= 10;
        }

        // Sirf exactly 2 occurrences count hongi
        if (count == 2)
            answer++;
    }

    // Zero ko bhi ek digit maana jayega
    if (n == 0)
        answer = 0; // 0 sirf ek baar aata hai

    cout << answer;
    return 0;
}
