// 42. Game Level Unlock Pattern
// Level: Hard
// Case: Game ke har level par required points ka rule hai: har row mein points i × j hain. Agar points 10 se zyada hain, U (unlocked) print karo; otherwise points print karo.
// Example: n = 5
// 1 2 3 4 5
// 2 4 6 8 U
// 3 6 9 U U
// 4 8 U U U
// 5 U U U U
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int points = i * j;

            if (points > 10)
                cout << "U ";
            else
                cout << points << " ";
        }

        cout << '\n';
    }

    return 0;
}
// Logic: Har cell ka result pehle calculate karo, phir condition apply karo.

