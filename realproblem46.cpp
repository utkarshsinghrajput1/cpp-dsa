// 46. Water Bottle Production Line
// Problem: Factory mein N bottles produce karni hain. Har bottle ko fill karne mein F seconds aur seal karne mein S seconds lagte hain. Har 100 bottles ke baad 10-minute machine break hota hai, lekin final batch ke baad break nahi. Total production time calculate karo.
#include <iostream>
using namespace std;

int main() {
    int N, F, S;
    cin >> N >> F >> S;

    int totalTime = 0;

    for (int bottle = 1; bottle <= N; bottle++) {
        totalTime = totalTime + F + S;

        if (bottle % 100 == 0 && bottle < N)
            totalTime = totalTime + 600;
    }

    cout << "Total Production Time: "
         << totalTime << " seconds";

    return 0;
}