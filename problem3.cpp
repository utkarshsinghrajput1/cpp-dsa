 // Given two integers, n and m. The task is to check the relation between n and m. Print "less" if n < m,  "equal" if n == m, and "greater" if n > m.
/* Example
Input: n = 4, m = 8
Output: less
Explanation: 4 < 8 so print 'less'. */

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n < m)
        cout << "less";
    else if (n == m)
        cout << "equal";
    else
        cout << "greater";

    return 0;
}