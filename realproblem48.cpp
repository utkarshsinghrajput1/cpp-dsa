// 48. Grocery Inventory Expiry Rotation
// Problem: Grocery store mein N product batches hain. Har batch ka stock aur expiry ke remaining days input lo. Store ka rule hai ki 15 days ke andar expire hone wale batches ko priority par sell karna hai. Priority stock aur normal stock alag calculate karo.
#include <iostream>
using namespace std;

int main() {
    int N, stock, days;
    int priorityStock = 0;
    int normalStock = 0;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> stock >> days;

        if (days <= 0) {
            cout << "Batch " << i << ": EXPIRED" << endl;
        } else if (days <= 15) {
            priorityStock = priorityStock + stock;
            cout << "Batch " << i << ": PRIORITY" << endl;
        } else {
            normalStock = normalStock + stock;
            cout << "Batch " << i << ": NORMAL" << endl;
        }
    }

    cout << "Priority Stock: " << priorityStock << endl;
    cout << "Normal Stock: " << normalStock;

    return 0;
}