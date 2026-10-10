// 46.Digital Password Grid
// Level: Very Hard
// Case: Ek password grid mein har cell ka number i × j + i hai. Agar number 2 aur 3 dono se divisible hai, A; sirf 2 se divisible hai, B; sirf 3 se divisible hai, C; otherwise number print karo.
// Example: n = 4
// 2 3 4 5
// 4 A 8 10
// 6 9 A 15
// 8 A 16 20
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            int value = i * j + i;

            if (value % 2 == 0 && value % 3 == 0)
                cout << "A ";
            else if (value % 2 == 0)
                cout << "B ";
            else if (value % 3 == 0)
                cout << "C ";
            else
                cout << value << " ";
        }

        cout << '\n';
    }

    return 0;
}
// Logic: Formula + multiple divisibility conditions. Output ko formula se verify karna important hai.
