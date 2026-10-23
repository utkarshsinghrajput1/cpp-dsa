// Question 9 — Airport Runway Conflict Prevention
// Problem statement
// An airport has two runways and three flight requests. Each flight has a requested time, priority, occupancy duration and maximum permitted delay.

// Rules:
// - Emergency flights have priority 3, high-priority flights 2, and normal flights 1.
// - A runway needs a safety gap after a flight finishes.
// - Choose the highest-priority flight among those waiting.
// - If priorities tie, choose the earlier requested time.
// - Mark a flight overdue if its maximum delay is exceeded.

#include <iostream>
using namespace std;

int main() {
    int arrival1, arrival2, arrival3;
    int priority1, priority2, priority3;
    int duration1, duration2, duration3;
    int delay1, delay2, delay3;
    int safetyGap;

    cout << "Enter requested times for 3 flights: ";
    cin >> arrival1 >> arrival2 >> arrival3;

    cout << "Enter priorities (1=normal, 2=high, 3=emergency): ";
    cin >> priority1 >> priority2 >> priority3;

    cout << "Enter runway occupancy durations: ";
    cin >> duration1 >> duration2 >> duration3;

    cout << "Enter maximum permitted delays: ";
    cin >> delay1 >> delay2 >> delay3;

    cout << "Enter mandatory runway safety gap: ";
    cin >> safetyGap;

    if (arrival1 < 0 || arrival2 < 0 || arrival3 < 0 ||
        priority1 < 1 || priority1 > 3 ||
        priority2 < 1 || priority2 > 3 ||
        priority3 < 1 || priority3 > 3 ||
        duration1 <= 0 || duration2 <= 0 || duration3 <= 0 ||
        delay1 < 0 || delay2 < 0 || delay3 < 0 ||
        safetyGap < 0) {
        cout << "Invalid input.\n";
        return 0;
    }

    int done1 = 0, done2 = 0, done3 = 0;
    int missed1 = 0, missed2 = 0, missed3 = 0;

    // Time when each runway next becomes available
    int runway1Free = 0;
    int runway2Free = 0;

    int completed = 0, overdue = 0;
    int time = 0;

    while (completed + overdue < 3) {
        int selected = 0;
        int bestPriority = 0;
        int earliest = 1000000;

        // Select the highest-priority arrived flight.
        // Earlier requested time breaks priority ties.
        if (done1 == 0 && missed1 == 0 && arrival1 <= time) {
            if (priority1 > bestPriority ||
                (priority1 == bestPriority && arrival1 < earliest)) {
                selected = 1;
                bestPriority = priority1;
                earliest = arrival1;
            }
        }

        if (done2 == 0 && missed2 == 0 && arrival2 <= time) {
            if (priority2 > bestPriority ||
                (priority2 == bestPriority && arrival2 < earliest)) {
                selected = 2;
                bestPriority = priority2;
                earliest = arrival2;
            }
        }

        if (done3 == 0 && missed3 == 0 && arrival3 <= time) {
            if (priority3 > bestPriority ||
                (priority3 == bestPriority && arrival3 < earliest)) {
                selected = 3;
                bestPriority = priority3;
                earliest = arrival3;
            }
        }

        // No flight is ready yet.
        if (selected == 0) {
            time++;
            continue;
        }

        int requested = 0;
        int maxDelay = 0;
        int duration = 0;

        if (selected == 1) {
            requested = arrival1;
            maxDelay = delay1;
            duration = duration1;
        }
        else if (selected == 2) {
            requested = arrival2;
            maxDelay = delay2;
            duration = duration2;
        }
        else {
            requested = arrival3;
            maxDelay = delay3;
            duration = duration3;
        }

        // Reject flights that have exceeded their deadline.
        if (time > requested + maxDelay) {
            if (selected == 1) missed1 = 1;
            else if (selected == 2) missed2 = 1;
            else missed3 = 1;

            overdue++;
            cout << "Flight " << selected << " is overdue.\n";
            continue;
        }

        // Assign the first available runway.
        int runway = 0;

        if (runway1Free <= time) runway = 1;
        else if (runway2Free <= time) runway = 2;

        // Both runways are occupied; wait and retry.
        if (runway == 0) {
            time++;
            continue;
        }

        // Update the runway's next available time.
        if (runway == 1)
            runway1Free = time + duration + safetyGap;
        else
            runway2Free = time + duration + safetyGap;

        if (selected == 1) done1 = 1;
        else if (selected == 2) done2 = 1;
        else done3 = 1;

        completed++;

        cout << "Flight " << selected
             << " assigned to runway " << runway
             << " at time " << time << "\n";
    }

    cout << "\nCompleted flights: " << completed;
    cout << "\nOverdue flights: " << overdue << "\n";

    return 0;
}

// Important logic
// runway1Free and runway2Free store when each runway becomes available again. If a flight starts at time 10, takes 4 minutes and needs a 2-minute safety gap, that runway becomes available at time 16.

// The simulator processes only three flights and treats requested times as integer minutes.