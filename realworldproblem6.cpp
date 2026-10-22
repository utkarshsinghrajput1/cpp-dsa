// Question 6 — Emergency Rescue Dispatch Simulator
// Problem statement
// Three ambulances handle three emergency requests. Each request has an arrival time, severity and mission duration. Severity 3 is critical, 2 is high and 1 is normal.

// Rules:
// - Process requests as time advances.
// - Dispatch the highest-severity waiting request.
// - Break equal-severity ties using the earlier arrival.
// - Assign the lowest-numbered available ambulance.
// - An ambulance becomes available when its mission finishes.
// - A request is missed if it cannot be dispatched by its deadline.
// For this basic-loop version, the three requests are entered up front, and no arrays are used.

#include <iostream>
using namespace std;

int main() {
    int a1, a2, a3;
    int s1, s2, s3;
    int d1, d2, d3;
    int deadline1, deadline2, deadline3;

    cout << "Enter arrival times of 3 requests: ";
    cin >> a1 >> a2 >> a3;

    cout << "Enter severity levels (1-3): ";
    cin >> s1 >> s2 >> s3;

    cout << "Enter mission durations: ";
    cin >> d1 >> d2 >> d3;

    cout << "Enter dispatch deadlines: ";
    cin >> deadline1 >> deadline2 >> deadline3;

    if (a1 < 0 || a2 < 0 || a3 < 0 ||
        s1 < 1 || s1 > 3 || s2 < 1 || s2 > 3 ||
        s3 < 1 || s3 > 3 ||
        d1 <= 0 || d2 <= 0 || d3 <= 0 ||
        deadline1 < a1 || deadline2 < a2 ||
        deadline3 < a3) {
        cout << "Invalid input.\n";
        return 0;
    }

    int done1 = 0, done2 = 0, done3 = 0;
    int missed1 = 0, missed2 = 0, missed3 = 0;

    int available1 = 0, available2 = 0, available3 = 0;
    int currentTime = 0;
    int completed = 0, missed = 0;

    // Process requests until all three are resolved.
    while (completed + missed < 3) {
        int selected = 0;
        int bestSeverity = 0;
        int earliest = 1000000;

        // Find the highest-severity request that has arrived.
        if (done1 == 0 && missed1 == 0 && a1 <= currentTime) {
            if (s1 > bestSeverity ||
                (s1 == bestSeverity && a1 < earliest)) {
                selected = 1;
                bestSeverity = s1;
                earliest = a1;
            }
        }

        if (done2 == 0 && missed2 == 0 && a2 <= currentTime) {
            if (s2 > bestSeverity ||
                (s2 == bestSeverity && a2 < earliest)) {
                selected = 2;
                bestSeverity = s2;
                earliest = a2;
            }
        }

        if (done3 == 0 && missed3 == 0 && a3 <= currentTime) {
            if (s3 > bestSeverity ||
                (s3 == bestSeverity && a3 < earliest)) {
                selected = 3;
                bestSeverity = s3;
                earliest = a3;
            }
        }

        // If no request has arrived, advance time.
        if (selected == 0) {
            currentTime++;
            continue;
        }

        int deadline = 0;

        if (selected == 1) deadline = deadline1;
        else if (selected == 2) deadline = deadline2;
        else deadline = deadline3;

        // Check the deadline before dispatch.
        if (currentTime > deadline) {
            if (selected == 1) missed1 = 1;
            else if (selected == 2) missed2 = 1;
            else missed3 = 1;

            missed++;
            cout << "Request " << selected << " missed.\n";
            continue;
        }

        // Find the first available ambulance.
        int ambulance = 0;

        if (available1 <= currentTime) ambulance = 1;
        else if (available2 <= currentTime) ambulance = 2;
        else if (available3 <= currentTime) ambulance = 3;

        // If all ambulances are busy, wait.
        if (ambulance == 0) {
            currentTime++;
            continue;
        }

        int duration = 0;
        if (selected == 1) duration = d1;
        else if (selected == 2) duration = d2;
        else duration = d3;

        // Mark the selected ambulance busy.
        if (ambulance == 1)
            available1 = currentTime + duration;
        else if (ambulance == 2)
            available2 = currentTime + duration;
        else
            available3 = currentTime + duration;

        if (selected == 1) done1 = 1;
        else if (selected == 2) done2 = 1;
        else done3 = 1;

        completed++;

        cout << "Request " << selected
             << " dispatched using ambulance " << ambulance
             << " at time " << currentTime << "\n";
    }

    cout << "\nCompleted: " << completed;
    cout << "\nMissed: " << missed << "\n";

    return 0;
}


// Important logic
// available1, available2 and available3 store the time when each ambulance will be free. A mission beginning at time 5 with duration 3 makes that ambulance available again at time 8.

// This simplified simulation dispatches requests in priority order among those already waiting. A full rescue system would also need to account for location, ambulance compatibility and travel time.