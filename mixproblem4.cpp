// 4. Longest Substring Without Repeating Characters
// Difficulty: Hard
// Question: String ki longest substring ki length find karo jisme koi character repeat na ho.
// Input:
// pwwkew

// Output:
// 3
// "wke" ki length 3 hai.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> lastSeen(256, -1);
    int left = 0;
    int best = 0;

    for (int right = 0; right < (int)s.size(); right++) {
        unsigned char ch = s[right];

        if (lastSeen[ch] >= left)
            left = lastSeen[ch] + 1;

        lastSeen[ch] = right;

        int length = right - left + 1;

        if (length > best)
            best = length;
    }

    cout << best;
    return 0;
}




// Logic: for loop right boundary move karta hai. Duplicate character current window mein ho toh if left boundary ko aage move karta hai.
// - Time: \(O(n)\)
// - Extra space: \(O(1)\) for a fixed-size character table.
