// 3. Trapping Rain Water
// Difficulty: Hard
// Question: Heights ki array di gayi hai. Bars ke beech kitna total rainwater trap hoga, calculate karo.
// Example:
// Input:
// 12
// 0 1 0 2 1 0 1 3 2 1 2 1

// Output:
// 6


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 0) {
        cout << "Invalid input";
        return 0;
    }

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i];

        if (h[i] < 0) {
            cout << "Invalid height";
            return 0;
        }
    }

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    long long water = 0;

    while (left < right) {
        if (h[left] <= h[right]) {
            if (h[left] >= leftMax)
                leftMax = h[left];
            else
                water += leftMax - h[left];

            left++;
        } else {
            if (h[right] >= rightMax)
                rightMax = h[right];
            else
                water += rightMax - h[right];

            right--;
        }
    }

    cout << water;
    return 0;
}
// Logic: Do pointers dono ends se move karte hain. Jis side ki height chhoti hai, us side ka water level calculate kiya ja sakta hai.
// - Time: \(O(n)\)
// - Extra space: \(O(1)\), input array ke alawa.
