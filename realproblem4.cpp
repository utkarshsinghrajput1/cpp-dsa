// 4. Monthly Household Budget Controller
// Problem: Monthly budget aur N expenses input lo. Agar expense budget cross kar deta hai toh BUDGET EXCEEDED print karo. End mein remaining budget ya overspending calculate karo

#include <iostream>
using namespace std;

int main() {
    double budget, expense, total = 0;
    int N;
    cin >> budget >> N;

    for (int i = 1; i <= N; i++) {
        cin >> expense;
        total = total + expense;

        if (total > budget)
            cout << "Budget crossed at expense " << i << endl;
    }

    if (total > budget)
        cout << "Overspending: " << total - budget;
    else
        cout << "Remaining: " << budget - total;

    return 0;
}