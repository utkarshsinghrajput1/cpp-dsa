// 44.Warehouse Inventory Checker
// Level: Hard
// Case: Warehouse mein har row ek shelf aur har column ek item ko represent karta hai. Har cell mein i + j ki value hai. Agar value even hai, E; odd hai, O print karo.
// Example: n = 5
// E O E O E
// O E O E O
// E O E O E
// O E O E O
// E O E O E
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            int value = i + j;

            if (value % 2 == 0)
                cout << "E ";
            else
                cout << "O ";
        }

        cout << '\n';
    }

    return 0;
}
// Logic: Row aur column ko combine karke condition evaluate karni hai.
