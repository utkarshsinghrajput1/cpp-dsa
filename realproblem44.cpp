// 44. Restaurant Kitchen Order Processing
// Problem: Kitchen mein N orders hain. Har order ke preparation time aur deadline input lo. Agar preparation time deadline se zyada hai toh late order mark karo. Total late orders aur total preparation time print karo.
#include <iostream>
using namespace std;

int main() {
    int N, preparation, deadline;
    int late = 0, totalTime = 0;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> preparation >> deadline;

        totalTime = totalTime + preparation;

        if (preparation > deadline) {
            late++;
            cout << "Order " << i << ": LATE" << endl;
        } else {
            cout << "Order " << i << ": ON TIME" << endl;
        }
    }

    cout << "Late Orders: " << late << endl;
    cout << "Total Preparation Time: " << totalTime;

    return 0;
}