// 40. Bank Vault Access Matrix
// Level: Hard
// Case: Ek bank vault mein n × n security grid hai. 
// Har cell ka number uski row aur column ke difference par depend karta hai. 
// Agar row aur column same hain, 9 print karo; agar unka sum n - 1 hai, 7 print karo; baaki cells mein 0.
// Example: n = 5
// 9 0 0 0 7
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << "9 ";
            else if (i + j == n - 1)
                cout << "7 ";
            else
                cout << "0 ";
        }
        cout << '\n';
    }

    return 0;
}
// Logic: Do diagonal conditions ko identify karna hai.