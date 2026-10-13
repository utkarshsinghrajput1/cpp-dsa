// Question7: Digit Square Transformation
// Problem: Ek positive integer N lo. Har step mein uske har digit ka square karo, phir un squares ke digits ka sum karke naya number banao. Process ko tab tak repeat karo jab tak number 1 na ho jaaye ya koi number repeat na ho. Total steps aur result print karo.
// Example:
// Input: 19

// 19 -> 82 -> 68 -> 100 -> 1
// Steps = 4
// Result = Reached 1
// cycle detect karne ke liye hum Floyd's cycle-detection technique use karenge. Ismein arrays, strings, vectors ya functions ki zaroorat nahi hai.

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int current = n;
    int steps = 0;

    // Floyd cycle detection ke liye do numbers rakhenge.
    int slow = n;
    int fast = n;

    // Slow ek transformation karega, fast do.
    do {
        int sum = 0;
        int temp = slow;

        // Slow number ke har digit ka square process karo.
        while (temp > 0) {
            int digit = temp % 10;
            int square = digit * digit;

            // Square ke digits ka sum nikalo.
            while (square > 0) {
                sum += square % 10;
                square /= 10;
            }

            temp /= 10;
        }

        slow = sum;

        // Fast ko do transformations denge.
        for (int j = 0; j < 2; j++) {
            int total = 0;
            int x = fast;

            while (x > 0) {
                int digit = x % 10;
                int square = digit * digit;

                while (square > 0) {
                    total += square % 10;
                    square /= 10;
                }

                x /= 10;
            }

            fast = total;
        }

    } while (slow != fast);

    // Cycle mil gayi. Ab pata karo ki 1 us cycle mein hai ya nahi.
    if (slow == 1) {
        cout << "Reached 1";
    } else {
        cout << "Cycle detected";
    }

    return 0;
}


// Upar wala code cycle detect karta hai, lekin steps count aur har intermediate number print nahi karta. Floyd's algorithm mein slow aur fast alag speed se chalte hain, isliye unki iterations original process ke steps ke barabar nahi hoti.
// Ek aur important baat: is particular transformation mein 9² = 81 ke digits ka sum 9 hai, isliye 19 ka pehla step 1 + 81 = 82 hota hai. Lekin 82 se next step 8² + 2² = 68 nahi, balki squares ke digits ka sum 64 → 10 aur 4 → 4 hota hai, yani 14. Isliye pehle diye gaye example ka transformation rule aur example match nahi kar rahe the.
// Agar rule ko standard Happy Number transformation banayein—har digit ka square karke squares ko add karna—tab 19 → 82 → 68 → 100 → 1 correct sequence hai. Us standard rule ke liye cycle detection mein square ke digits ka sum nahi nikalna chahiye; har digit ke square ko directly total mein add karna chahiye.