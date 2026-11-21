// 42. Cinema Hall Seat Revenue
// Problem: Cinema hall mein R rows aur S seats per row hain. Har row ka ticket price alag hai. Har seat ka status input lo: 1 booked, 0 empty. Total revenue aur empty seats calculate karo.
#include <iostream>
using namespace std;

int main() {
    int R, S, status;
    double price, revenue = 0;
    int empty = 0;

    cin >> R >> S;

    for (int row = 1; row <= R; row++) {
        cin >> price;

        int booked = 0;

        for (int seat = 1; seat <= S; seat++) {
            cin >> status;

            if (status == 1) {
                revenue = revenue + price;
                booked++;
            } else if (status == 0) {
                empty++;
            }
        }

        cout << "Row " << row
             << " Booked: " << booked << endl;
    }

    cout << "Total Revenue: " << revenue << endl;
    cout << "Empty Seats: " << empty;

    return 0;
}