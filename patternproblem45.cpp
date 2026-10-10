// 45.Racing Tournament Ranking
// Level: Hard
// Case: Har player ki row mein ranking numbers print karo. Row number i par sequence i, i+2, i+4... hogi. Agar number 10 se bada ho, X print karo.
// Example: n = 5
// 1
// 2 4
// 3 5 7
// 4 6 8 X
// 5 7 9 X X
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int value = i;

        for (int j = 1; j <= i; j++) {

            if (value > 10)
                cout << "X ";
            else
                cout << value << " ";

            value += 2;
        }

        cout << '\n';
    }

    return 0;
}
// Logic: Har row ke liye value reset hoti hai, lekin inner loop mein 2 se increase hoti hai.