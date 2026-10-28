// Problem 24: Water-Pipeline Leak Detection
// Question: 3 pipeline segments ke input aur output water-flow readings hain. Agar input-output difference 10 units se zyada ho, toh suspicious reading count karo. Ek segment par 3 consecutive suspicious readings aane par critical alert do.

#include <iostream>
using namespace std;

int main() {
    int suspicious1 = 0;
    int suspicious2 = 0;
    int suspicious3 = 0;

    int critical1 = 0;
    int critical2 = 0;
    int critical3 = 0;

    int readings = 5;

    for (int i = 1; i <= readings; i++) {
        int in1, out1, in2, out2, in3, out3;

        cout << "Enter input/output for 3 segments:\n";
        cin >> in1 >> out1 >> in2 >> out2 >> in3 >> out3;

        // Segment 1: consecutive suspicious readings
        if (in1 - out1 > 10) {
            suspicious1++;
            if (suspicious1 >= 3 && critical1 == 0) {
                critical1 = 1;
                cout << "Critical leak alert: Segment 1\n";
            }
        } else {
            suspicious1 = 0; // Reset streak after a normal reading
        }

        // Segment 2
        if (in2 - out2 > 10) {
            suspicious2++;
            if (suspicious2 >= 3 && critical2 == 0) {
                critical2 = 1;
                cout << "Critical leak alert: Segment 2\n";
            }
        } else {
            suspicious2 = 0;
        }

        // Segment 3
        if (in3 - out3 > 10) {
            suspicious3++;
            if (suspicious3 >= 3 && critical3 == 0) {
                critical3 = 1;
                cout << "Critical leak alert: Segment 3\n";
            }
        } else {
            suspicious3 = 0;
        }
    }

    cout << "\nCritical segments detected:\n";
    cout << "Segment 1: " << critical1 << "\n";
    cout << "Segment 2: " << critical2 << "\n";
    cout << "Segment 3: " << critical3 << "\n";

    return 0;
}

// Important logic:
// - in - out estimated water loss deta hai.
// - Consecutive counter normal reading par reset hota hai.
// - critical flag repeated alert ko prevent karta hai.
// - Yeh educational simulation hai; actual leak detection ke liye calibrated sensors aur more checks chahiye.
