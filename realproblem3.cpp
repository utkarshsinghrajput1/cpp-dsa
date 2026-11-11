// 3. Bank Loan Repayment Simulator
// Problem: Loan amount, monthly payment aur monthly interest rate input lo. Har month interest add karo aur payment subtract karo. Jab tak loan clear nahi hota, months count karo. Agar payment monthly interest se zyada nahi hai toh PAYMENT INSUFFICIENT print karo.
#include <iostream>
using namespace std;

int main() {
    double loan, payment, rate;
    int months = 0;

    cin >> loan >> payment >> rate;

    if (payment <= loan * rate / 100) {
        cout << "PAYMENT INSUFFICIENT";
    } else {
        while (loan > 0) {
            loan = loan + loan * rate / 100;
            loan = loan - payment;
            months++;

            if (loan < 0)
                loan = 0;
        }

        cout << "Months Required: " << months;
    }

    return 0;
}