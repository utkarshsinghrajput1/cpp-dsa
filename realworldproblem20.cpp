// Problem 20: Robot Collision Prevention
// Question: 3 robots ek straight track par move karte hain. Har step mein robot 1 position aage badhta hai. Agar do robots ki next positions same hon, toh higher-priority robot ko move karne do aur doosre ko rok do.

#include <iostream>
using namespace std;

int main() {
    int pos1 = 0, pos2 = 2, pos3 = 5;
    int priority1 = 3, priority2 = 2, priority3 = 1;

    int steps = 5;

    for (int i = 1; i <= steps; i++) {
        int next1 = pos1 + 1;
        int next2 = pos2 + 1;
        int next3 = pos3 + 1;

        // Check Robot 1 against Robot 2
        if (next1 == next2) {
            if (priority1 >= priority2) next2 = pos2;
            else next1 = pos1;
        }

        // Check Robot 1 against Robot 3
        if (next1 == next3) {
            if (priority1 >= priority3) next3 = pos3;
            else next1 = pos1;
        }

        // Check Robot 2 against Robot 3
        if (next2 == next3) {
            if (priority2 >= priority3) next3 = pos3;
            else next2 = pos2;
        }

        // Commit the updated positions
        pos1 = next1;
        pos2 = next2;
        pos3 = next3;

        cout << "Step " << i << ": "
             << pos1 << ", " << pos2 << ", " << pos3 << "\n";
    }

    cout << "\nFinal positions: "
         << pos1 << ", " << pos2 << ", " << pos3 << "\n";

    return 0;
}


#include <iostream>
using namespace std;

int main() {
    int pos1 = 0, pos2 = 2, pos3 = 5;
    int priority1 = 3, priority2 = 2, priority3 = 1;

    int steps = 5;

    for (int i = 1; i <= steps; i++) {
        int next1 = pos1 + 1;
        int next2 = pos2 + 1;
        int next3 = pos3 + 1;

        // Check Robot 1 against Robot 2
        if (next1 == next2) {
            if (priority1 >= priority2) next2 = pos2;
            else next1 = pos1;
        }

        // Check Robot 1 against Robot 3
        if (next1 == next3) {
            if (priority1 >= priority3) next3 = pos3;
            else next1 = pos1;
        }

        // Check Robot 2 against Robot 3
        if (next2 == next3) {
            if (priority2 >= priority3) next3 = pos3;
            else next2 = pos2;
        }

        // Commit the updated positions
        pos1 = next1;
        pos2 = next2;
        pos3 = next3;

        cout << "Step " << i << ": "
             << pos1 << ", " << pos2 << ", " << pos3 << "\n";
    }

    cout << "\nFinal positions: "
         << pos1 << ", " << pos2 << ", " << pos3 << "\n";

    return 0;
}
// Important logic:
// - next1, next2, next3 movement se pehle calculate hote hain.
// - Pairwise if statements collision risk check karte hain.
// - Higher priority robot ko movement milti hai.
// - Limitation: Yeh simple one-dimensional model hai. Complex simultaneous movement ke liye ek step mein multiple conflicts ka handling aur robust banana padega.
