// Q. Rock Paper Scissors
// User 1 aur User 2 choice denge
// 1 = Rock
// 2 = Paper
// 3 = Scissors
// Winner determine karo.
#include <iostream>
using namespace std;

int main() {
    int p1, p2;

    cout << "Player 1 (1=Rock, 2=Paper, 3=Scissors): ";
    cin >> p1;

    cout << "Player 2 (1=Rock, 2=Paper, 3=Scissors): ";
    cin >> p2;

    if (p1 == p2) {
        cout << "Draw";
    }
    else if ((p1 == 1 && p2 == 3) ||
             (p1 == 2 && p2 == 1) ||
             (p1 == 3 && p2 == 2)) {

        cout << "Player 1 Wins";
    }
    else if ((p2 == 1 && p1 == 3) ||
             (p2 == 2 && p1 == 1) ||
             (p2 == 3 && p1 == 2)) {

        cout << "Player 2 Wins";
    }
    else {
        cout << "Invalid choice";
    }

    return 0;
}