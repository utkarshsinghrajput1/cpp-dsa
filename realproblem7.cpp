// 7. Retail Store Profit and Loss Analyzer
// Problem: N products ke purchase cost aur selling price input lo. Har product ka profit/loss aur overall business profit calculate karo.
#include <iostream>
using namespace std;

int main() {
    int N;
    double cost, selling, total = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> cost >> selling;

        double result = selling - cost;
        total = total + result;

        if (result > 0)
            cout << "Profit: " << result << endl;
        else if (result < 0)
            cout << "Loss: " << -result << endl;
        else
            cout << "No Profit No Loss" << endl;
    }

    cout << "Net Business Result: " << total;
    return 0;
}