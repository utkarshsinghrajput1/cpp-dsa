// 6. Find the Sum of All Prime Numbers from 1 to N
// Example: Input 10 → Output 17 because 2 + 3 + 5 + 7 = 17.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long sum = 0;

    for (int num = 2; num <= n; num++) {
        bool prime = true;

        for (int i = 2; i <= num / i; i++) {
            if (num % i == 0) {
                prime = false;
                break;
            }
        }

        if (prime) {
            sum = sum + num;
        }
    }

    cout << "Sum of primes = " << sum;

    return 0;
}