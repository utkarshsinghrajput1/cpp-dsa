// Question 3 — Cybersecurity Login Attack Detector
// Problem statement
// A login system monitors three users. It locks an account after F consecutive failed logins and unlocks it after L time intervals.
// - Input the number of login events.
// - Each event contains a user ID (1, 2, or 3) and a result (1 for success, 0 for failure).
// - Locked accounts ignore login attempts until their lock duration expires.
// - Successful logins reset the consecutive-failure counter.

#include <iostream>
using namespace std;

int main() {
    int events, F, L;

    cout << "Enter number of login events: ";
    cin >> events;

    cout << "Enter failure limit F and lock duration L: ";
    cin >> F >> L;

    if (events < 0 || F <= 0 || L <= 0) {
        cout << "Invalid input.\n";
        return 0;
    }

    // Separate variables for three users
    int fail1 = 0, fail2 = 0, fail3 = 0;
    int success1 = 0, success2 = 0, success3 = 0;
    int locked1 = 0, locked2 = 0, locked3 = 0;
    int until1 = 0, until2 = 0, until3 = 0;

    int event = 1;

    while (event <= events) {
        int user, result;

        cout << "Enter user ID (1-3) and result (1=success, 0=failure): ";
        cin >> user >> result;

        if (user < 1 || user > 3 ||
            (result != 0 && result != 1)) {
            cout << "Invalid event. Try again.\n";
            continue;
        }

        // Each event is one time interval.
        // Unlock before processing the current attempt.
        if (user == 1 && locked1 == 1 && event >= until1)
            locked1 = 0;

        if (user == 2 && locked2 == 1 && event >= until2)
            locked2 = 0;

        if (user == 3 && locked3 == 1 && event >= until3)
            locked3 = 0;

        if ((user == 1 && locked1 == 1) ||
            (user == 2 && locked2 == 1) ||
            (user == 3 && locked3 == 1)) {

            cout << "Account locked. Attempt ignored.\n";
        }
        else {
            if (user == 1) {
                if (result == 1) {
                    success1++;
                    fail1 = 0;
                } else {
                    fail1++;

                    if (fail1 >= F) {
                        locked1 = 1;
                        until1 = event + L;
                    }
                }
            }
            else if (user == 2) {
                if (result == 1) {
                    success2++;
                    fail2 = 0;
                } else {
                    fail2++;

                    if (fail2 >= F) {
                        locked2 = 1;
                        until2 = event + L;
                    }
                }
            }
            else {
                if (result == 1) {
                    success3++;
                    fail3 = 0;
                } else {
                    fail3++;

                    if (fail3 >= F) {
                        locked3 = 1;
                        until3 = event + L;
                    }
                }
            }
        }

        event++;
    }

    cout << "\nUSER 1: failures=" << fail1
         << ", successes=" << success1
         << ", locked=" << locked1 << "\n";

    cout << "USER 2: failures=" << fail2
         << ", successes=" << success2
         << ", locked=" << locked2 << "\n";

    cout << "USER 3: failures=" << fail3
         << ", successes=" << success3
         << ", locked=" << locked3 << "\n";

    return 0;
}

// Important logic
// - fail1, fail2, and fail3 track consecutive failures independently.
// - until1, until2, and until3 store when the corresponding lock expires.
// - The event counter acts as the time interval.
// - The lock is checked before the current attempt is processed.
// Note: This is a simplified login simulator, not a production-ready security system.
