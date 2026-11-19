// 35. Factory Defective Product Rate
// Problem: N production batches hain. Har batch ke total products aur defective products input lo. Defect percentage 5% se zyada hone par batch reject karo.
#include <iostream>
using namespace std;

int main() {
    int N, produced, defective;
    int rejected = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> produced >> defective;

        if (produced <= 0 || defective < 0 ||
            defective > produced) {
            cout << "Invalid Batch" << endl;
        } else {
            double rate = defective * 100.0 / produced;

            cout << "Defect Rate: " << rate << "%" << endl;

            if (rate > 5) {
                rejected++;
                cout << "BATCH REJECTED" << endl;
            } else {
                cout << "BATCH ACCEPTED" << endl;
            }
        }
    }

    cout << "Rejected Batches: " << rejected;

    return 0;
}