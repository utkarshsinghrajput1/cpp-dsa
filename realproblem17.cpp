// 17. Train Coach Seat Allocation
// Problem: Train mein C coaches hain aur har coach mein S seats hain. N passengers ko seats allocate karo. Har coach mein available seats count karo. Total capacity se zyada passengers hone par waiting passengers count karo.
#include <iostream>
using namespace std;

int main() {
    int C, S, N;
    cin >> C >> S >> N;

    int totalSeats = C * S;
    int confirmed = 0;

    for (int coach = 1; coach <= C; coach++) {
        int seats = 0;

        for (int seat = 1; seat <= S; seat++) {
            if (confirmed < N) {
                confirmed++;
                seats++;
            }
        }

        cout << "Coach " << coach
             << " occupied seats: " << seats << endl;
    }

    cout << "Confirmed: " << confirmed << endl;
    cout << "Waiting: " << N - confirmed;

    return 0;
}