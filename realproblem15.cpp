// 15. Shipping Cost Optimization
// Problem: N parcels ke weights input lo. Shipping charge ₹50 base hai, aur har kilogram par ₹20 additional. 10 kg se heavy parcel par ₹100 extra handling charge lagao.

#include <iostream>
using namespace std;

int main() {
    int N;
    double weight, cost, total = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> weight;

        cost = 50 + weight * 20;

        if (weight > 10)
            cost = cost + 100;

        total = total + cost;
        cout << "Parcel " << i << ": " << cost << endl;
    }

    cout << "Total Shipping Cost: " << total;
    return 0;
}