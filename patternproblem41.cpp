// 41.Smart Traffic Signal Grid
// Level: Hard
// Case: Har intersection ko 1 se n² tak number diya gaya hai. Har number ke liye:
// - 3 aur 5 dono se divisible → G
// - Sirf 3 se divisible → R
// - Sirf 5 se divisible → Y
// - Dono se divisible nahi → number print karo.
// Example: n = 4
// 1 2 R 4
// Y R 7 8
// R Y 11 R
// 13 14 R Y
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int num = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            if (num % 3 == 0 && num % 5 == 0)
                cout << "G ";
            else if (num % 3 == 0)
                cout << "R ";
            else if (num % 5 == 0)
                cout << "Y ";
            else
                cout << num << " ";

            num++;
        }

        cout << '\n';
    }

    return 0;
}
// Logic: Multiple conditions mein order important hai. Dono divisors wali condition sabse pehle check karo.