// Question 16: Prime Pair Lock
// N tak ke sabhi numbers mein aise pairs (a, b) find karo jahan:
// - a aur b dono prime hon.
// - b - a = 2.
// - a + b bhi prime ho.
// Example: N = 20
// Twin prime pairs mein (3,5), (5,7), (11,13), (17,19) aate hain. Inmein se check karna hai ki pair ka sum bhi prime hai ya nahi.
// Output mein sirf valid pairs print karna.
// Concept: nested for loops, nested divisibility checks, if-else.
// Task: Aise prime pairs print karo jinka difference 2 ho aur sum bhi prime ho.
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int a = 2; a + 2 <= N; a++) {
        int b = a + 2;

        // Check whether a is prime
        bool primeA = true;

        for (int d = 2; d * d <= a; d++) {
            if (a % d == 0) {
                primeA = false;
                break;
            }
        }

        // Check whether b is prime
        bool primeB = true;

        for (int d = 2; d * d <= b; d++) {
            if (b % d == 0) {
                primeB = false;
                break;
            }
        }

        int sum = a + b;
        bool primeSum = true;

        for (int d = 2; d * d <= sum; d++) {
            if (sum % d == 0) {
                primeSum = false;
                break;
            }
        }

        if (primeA && primeB && primeSum) {
            cout << "(" << a << ", " << b << ")\n";
        }
    }

    return 0;
}

// Logic: 3 + 5 = 8 prime nahi hai, so (3,5) actually valid nahi hai. Similarly, 5 + 7 = 12 bhi prime nahi hai. Isliye upar diye code ke liye correct output empty hoga. Ye question jaan-boojhkar tricky hai: do twin primes ka sum hamesha even hota hai, aur 2 se bada even number prime nahi hota. Isliye is problem ka koi valid pair nahi hai.
