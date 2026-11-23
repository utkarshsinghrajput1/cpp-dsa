// 47. Event Registration Capacity Controller
// Problem: Event mein H halls hain aur har hall ki capacity C hai. Har registration ke saath participants ki group size input lo. Group ko ek hi hall mein accommodate karna hai; group ko divide nahi karna. Nested loops se groups allocate karo. Jo groups fit nahi hote unhe reject karo.
#include <iostream>
using namespace std;

int main() {
    int H, C, N, group;
    cin >> H >> C >> N;

    int accepted = 0;
    int rejected = 0;

    for (int hall = 1; hall <= H; hall++) {
        int remaining = C;

        for (int registration = 1;
             registration <= N; registration++) {

            cin >> group;

            if (group > 0 && group <= remaining) {
                remaining = remaining - group;
                accepted++;
            } else {
                rejected++;
            }
        }

        cout << "Hall " << hall
             << " Remaining Seats: " << remaining << endl;
    }

    cout << "Accepted Groups: " << accepted << endl;
    cout << "Rejected Groups: " << rejected;

    return 0;
}


// Note: Is particular problem mein har hall ke liye registrations dobara input honge. Isliye input sequence hall-wise dena hoga.