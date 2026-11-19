// 33. Manufacturing Production Target
// Problem: Factory ko T products manufacture karne hain. Har day production input lo. Target complete hone tak days count karo. Target complete hone ke baad extra production bhi calculate karo.
#include <iostream>
using namespace std;

int main() {
    int target, production;
    int total = 0, days = 0;

    cin >> target;

    while (total < target) {
        cin >> production;

        if (production < 0) {
            cout << "Invalid production" << endl;
        } else {
            total = total + production;
            days++;
        }
    }

    cout << "Days Required: " << days << endl;
    cout << "Extra Production: " << total - target;

    return 0;
}