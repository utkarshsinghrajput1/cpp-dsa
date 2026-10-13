// 5. Largest Rectangle in a Histogram
// Difficulty: Hard
// Question: Histogram ki bar heights di hui hain. Find karo ki sabse bada rectangle kitna area cover kar sakta hai.
// Input:
// 6
// 2 1 5 6 2 3

// Output:
// 10
// Bars of heights 5 aur 6 milkar area 2 × 5 = 10 dete hain.

#include <iostream>
#include <vector>
#include <algorithm>
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

    vector<int> st;
    long long best = 0;

    for (int i = 0; i <= n; i++) {
        int currentHeight = (i == n ? 0 : h[i]);

        while (!st.empty() &&
               h[st.back()] > currentHeight) {
            int height = h[st.back()];
            st.pop_back();

            int width = st.empty()
                      ? i
                      : i - st.back() - 1;

            long long area = 1LL * height * width;

            if (area > best)
                best = area;
        }

        if (i < n)
            st.push_back(i);
    }

    cout << best;
    return 0;
}
// Logic: Monotonic stack mein increasing heights ke indices rakhe jaate hain. Jab chhoti height milti hai, toh pehle wali height ka maximum possible rectangle calculate hota hai.
// - Time: \(O(n)\)
// - Extra space: \(O(n)\).
