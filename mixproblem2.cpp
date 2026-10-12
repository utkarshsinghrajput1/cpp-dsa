// Problem 2: Longest Increasing Streak
// Difficulty: Medium
// Loop + If-Else

// Interview-style question
// User se n numbers input lo. Find karo ki consecutive numbers ki sabse lambi strictly increasing streak kitni hai.
// Strictly increasing ka matlab har next number, previous number se bada hona chahiye.
// Example:
// Input:
// 8
// 3 5 7 2 4 6 8 1

// Output:
// Longest increasing streak: 4
// Explanation:
// - 3, 5, 7 ki length = 3
// - 2, 4, 6, 8 ki length = 4
// - 1 ki length = 1
// Answer 4 hai.

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input";
        return 0;
    }

    int previous;
    cin >> previous;

    int currentStreak = 1;
    int longestStreak = 1;

    for (int i = 1; i < n; i++) {
        int current;
        cin >> current;

        if (current > previous) {
            currentStreak++;
        } else {
            currentStreak = 1;
        }

        if (currentStreak > longestStreak) {
            longestStreak = currentStreak;
        }

        previous = current;
    }

    cout << "Longest increasing streak: "
         << longestStreak;

    return 0;
}
