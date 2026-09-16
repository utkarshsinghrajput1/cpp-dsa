// Find sum of all even number from 1 to n
// Solution: We can use a for loop to iterate through all even numbers from 2 to n and keep adding them to a sum variable. Finally, we will print the sum.

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0;

    // 2 se start karenge aur har baar 2 increase karenge
    // Isse sirf even numbers milenge: 2, 4, 6, 8...
    for (int i = 2; i <= n; i += 2) {
        sum = sum + i;
    }

    cout << "Sum of even numbers = " << sum << endl;

    return 0;
}