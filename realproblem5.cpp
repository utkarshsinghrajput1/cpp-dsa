// 5. Restaurant Table Revenue Analyzer
// Problem: Restaurant mein T tables hain. Har table ke customers ki count aur per-customer bill input lo. Har table ka revenue aur restaurant ka total revenue calculate karo. Agar kisi table ka revenue ₹3,000 se zyada hai toh VIP table mark karo.
#include <iostream>
using namespace std;

int main() {
    int T, customers;
    double bill, revenue, total = 0;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        cin >> customers >> bill;

        revenue = customers * bill;
        total = total + revenue;

        cout << "Table " << i << ": " << revenue;

        if (revenue > 3000)
            cout << " VIP";

        cout << endl;
    }

    cout << "Total Revenue: " << total;
    return 0;
}