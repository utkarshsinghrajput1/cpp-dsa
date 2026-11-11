// 1. Supermarket Dynamic Billing System
// Problem: Ek customer N products purchase karta hai. Har product ki price input lo. Total bill calculate karo. Agar bill ₹5,000 se zyada hai toh 10% discount, ₹2,000 se zyada hai toh 5% discount, otherwise no discount. Final bill print karo.
#include <iostream>
using namespace std;

int main() {
    int N;
    double price, total = 0, discount = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> price;
        total = total + price;
    }

    if (total > 5000)
        discount = total * 0.10;
    else if (total > 2000)
        discount = total * 0.05;

    cout << "Original Bill: " << total << endl;
    cout << "Discount: " << discount << endl;
    cout << "Final Bill: " << total - discount;

    return 0;
}