// 23. Medicine Stock Expiry Monitor
// Problem: Pharmacy ke N medicine batches ke remaining shelf-life days aur stock quantity input lo. 30 days se kam shelf life hone par warning do. Expired medicines ko usable stock mein include mat kar
#include <iostream>
using namespace std;

int main() {
    int N, days, quantity;
    int usable = 0, expired = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> days >> quantity;

        if (days <= 0) {
            expired = expired + quantity;
            cout << "EXPIRED BATCH" << endl;
        } else {
            usable = usable + quantity;

            if (days <= 30)
                cout << "EXPIRY WARNING" << endl;
            else
                cout << "SAFE STOCK" << endl;
        }
    }

    cout << "Usable Quantity: " << usable << endl;
    cout << "Expired Quantity: " << expired;

    return 0;
}