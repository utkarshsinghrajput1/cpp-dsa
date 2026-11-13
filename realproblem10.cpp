// 10. Business Break-Even Calculator
// Problem: Business ka fixed cost, per-product selling price aur per-product production cost input lo. Calculate karo minimum kitne products sell karne par business break-even point tak pahunchega.
#include <iostream>
using namespace std;

int main() {
    double fixedCost, selling, production;
    cin >> fixedCost >> selling >> production;

    if (selling <= production) {
        cout << "Break-even not possible";
    } else {
        double contribution = selling - production;
        int quantity = 0;
        double profit = -fixedCost;

        while (profit < 0) {
            profit = profit + contribution;
            quantity++;
        }

        cout << "Break-even Quantity: " << quantity;
    }

    return 0;
}