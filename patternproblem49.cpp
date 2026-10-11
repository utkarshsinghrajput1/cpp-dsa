// 49.The Ultimate Conditional Matrix
// Level: Boss Fight
// Case: Har cell ke liye value = i × j calculate karo. Phir:
// - Main diagonal (i == j) → D
// - Value even ho → E
// - Value odd ho aur 3 se divisible ho → T
// - Otherwise → value print karo.
// Example: n = 5
// D 2 T 4 T
// 2 D E E 10
// T E D 12 15
// 4 E 12 D E
// T 10 15 E D
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            int value = i * j;

            if (i == j)
                cout << "D ";
            else if (value % 2 == 0)
                cout << "E ";
            else if (value % 3 == 0)
                cout << "T ";
            else
                cout << value << " ";
        }

        cout << '\n';
    }

    return 0;
}
// Logic: Coordinate condition ko divisibility conditions se pehle check karna hai, kyunki diagonal ki priority sabse high hai.