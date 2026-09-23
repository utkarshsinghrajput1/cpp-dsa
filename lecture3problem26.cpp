// 26. Loan Repayment Calculator
// Problem: Ek dost ne Rs. 10,000 ka loan liya hai aur wo har mahine Rs. 2,500 wapas karta hai. 
// Jab tak loan clear nahi hota, mahine gino.
#include <iostream>
using namespace std;
int main() {
    int loan = 10000;
    int monthly_pay = 2500;
    int month = 0;
    while (loan > 0) {
        month++;
        loan -= monthly_pay;
        cout << "Month " << month << " -> Remaining loan: Rs. " << loan << endl;
    }
    return 0;
}