// 49. Digital Payment Installment Tracker
// Problem: Customer ko total purchase amount ki installments pay karni hain. Har installment ka amount input lo. Jab total paid amount purchase amount ke equal ya usse zyada ho jaye toh payment complete mark karo. Kitni installments lagi aur kitna extra payment hua, calculate karo.
#include <iostream>
using namespace std;

int main() {
    double purchase, installment;
    int count = 0;
    double paid = 0;

    cin >> purchase;

    if (purchase <= 0) {
        cout << "Invalid Purchase";
    } else {
        while (paid < purchase) {
            cin >> installment;

            if (installment <= 0) {
                cout << "Invalid Installment" << endl;
            } else {
                paid = paid + installment;
                count++;
            }
        }

        cout << "Payment Complete" << endl;
        cout << "Installments: " << count << endl;
        cout << "Extra Payment: " << paid - purchase;
    }

    return 0;
}