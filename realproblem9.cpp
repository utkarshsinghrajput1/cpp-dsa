// 9. Subscription Renewal Tracker
// Problem: Ek company ke N customers ki subscription remaining days input lo. Har month 30 days ka hai. 7 days ya usse kam remaining hone par renewal reminder print karo. Expired subscriptions alag count karo.
#include <iostream>
using namespace std;

int main() {
    int N, days;
    int expired = 0, reminders = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> days;

        if (days <= 0) {
            expired++;
            cout << "Customer " << i << ": EXPIRED" << endl;
        } else if (days <= 7) {
            reminders++;
            cout << "Customer " << i << ": RENEW NOW" << endl;
        } else {
            cout << "Customer " << i << ": ACTIVE" << endl;
        }
    }

    cout << "Expired: " << expired << endl;
    cout << "Renewal Reminders: " << reminders;

    return 0;
}