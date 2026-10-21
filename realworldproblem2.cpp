// Question 2 — Zero-Defect Smart Factory
// Problem statement
// Three machines manufacture products. Each machine has a production rate, defects per production hour, a maximum defect limit and a maintenance interval.

// The factory must stop a machine when its cumulative defects exceed its limit, pause machines for maintenance, and stop when the target number of usable products is reached or the shift ends.

// Assumptions: A machine produces its specified quantity and defects in each production hour. Maintenance occurs before production in an hour divisible by that machine's maintenance interval. A machine is stopped permanently if its defect limit is exceeded.

#include <iostream>
using namespace std;

int main() {
    int target, shiftHours;

    int cap1, cap2, cap3;
    int defect1, defect2, defect3;
    int limit1, limit2, limit3;
    int maint1, maint2, maint3;

    cout << "Enter target usable products: ";
    cin >> target;

    cout << "Enter shift duration in hours: ";
    cin >> shiftHours;

    cout << "Enter capacity per hour for 3 machines: ";
    cin >> cap1 >> cap2 >> cap3;

    cout << "Enter defects per production hour: ";
    cin >> defect1 >> defect2 >> defect3;

    cout << "Enter maximum defect limits: ";
    cin >> limit1 >> limit2 >> limit3;

    cout << "Enter maintenance intervals: ";
    cin >> maint1 >> maint2 >> maint3;

    if (target <= 0 || shiftHours <= 0 ||
        cap1 <= 0 || cap2 <= 0 || cap3 <= 0 ||
        defect1 < 0 || defect2 < 0 || defect3 < 0 ||
        limit1 < 0 || limit2 < 0 || limit3 < 0 ||
        maint1 <= 0 || maint2 <= 0 || maint3 <= 0) {
        cout << "Invalid input.\n";
        return 0;
    }

    int usable = 0;
    int totalDefects = 0;
    int downtime = 0;

    int active1 = 1, active2 = 1, active3 = 1;
    int hour = 1;

    while (hour <= shiftHours && usable < target) {
        int produced = 0;
        int defectsThisHour = 0;
        int maintenanceNow = 0;

        // Machine 1
        if (active1 == 1 && usable < target) {
            if (hour % maint1 == 0) {
                maintenanceNow = 1;
            } else {
                produced = cap1;
                defectsThisHour = defect1;

                totalDefects += defect1;

                if (totalDefects > limit1) {
                    active1 = 0;
                } else {
                    usable += cap1 - defect1;
                }
            }
        }

        // Machine 2
        if (active2 == 1 && usable < target) {
            if (hour % maint2 == 0) {
                maintenanceNow = 1;
            } else {
                produced = cap2;
                defectsThisHour = defect2;

                // Track machine 2 defects separately
                static int machine2Defects = 0;
                machine2Defects += defect2;
                totalDefects += defect2;

                if (machine2Defects > limit2) {
                    active2 = 0;
                } else {
                    usable += cap2 - defect2;
                }
            }
        }

        // Machine 3
        if (active3 == 1 && usable < target) {
            if (hour % maint3 == 0) {
                maintenanceNow = 1;
            } else {
                produced = cap3;
                defectsThisHour = defect3;

                static int machine3Defects = 0;
                machine3Defects += defect3;
                totalDefects += defect3;

                if (machine3Defects > limit3) {
                    active3 = 0;
                } else {
                    usable += cap3 - defect3;
                }
            }
        }

        if (maintenanceNow == 1) {
            downtime++;
        }

        cout << "Hour " << hour
             << " | Usable products: " << usable
             << " | Total defects: " << totalDefects << "\n";

        if (active1 == 0 && active2 == 0 && active3 == 0) {
            cout << "All machines have stopped.\n";
            break;
        }

        hour++;
    }

    cout << "\nFinal usable products: " << usable;
    cout << "\nTotal defects: " << totalDefects;
    cout << "\nMaintenance downtime hours: " << downtime;

    if (usable >= target) {
        cout << "\nProduction target achieved.\n";
    } else {
        cout << "\nProduction target not achieved.\n";
    }

    return 0;
}




// Important correction for learning: The code above illustrates the simulation structure, but usable is shared across machines, so the production target check can prevent later machines from operating in the same hour. Also, machine 1 needs its own cumulative defect counter just like machines 2 and 3. For an accurate production model, each machine should track its own defects, and the factory should calculate each hour's total production before applying the target stop. These are exactly the kinds of edge cases you should learn to catch while testing.


// Important correction for learning: The code above illustrates the simulation structure, but usable is shared across machines, so the production target check can prevent later machines from operating in the same hour. Also, machine 1 needs its own cumulative defect counter just like machines 2 and 3. For an accurate production model, each machine should track its own defects, and the factory should calculate each hour's total production before applying the target stop. These are exactly the kinds of edge cases you should learn to catch while testing.


// Corrected, copy-ready version for Question 2
// Bhai, use this version instead of the earlier Question 2 code. It tracks each machine's defects separately and processes all machines for the current hour before checking the factory's target.

// #include <iostream>
// using namespace std;

// int main() {
//     int target, shiftHours;
//     int cap1, cap2, cap3;
//     int defect1, defect2, defect3;
//     int limit1, limit2, limit3;
//     int maint1, maint2, maint3;

//     cout << "Enter target and shift hours: ";
//     cin >> target >> shiftHours;

//     cout << "Enter capacities of 3 machines: ";
//     cin >> cap1 >> cap2 >> cap3;

//     cout << "Enter defects per production hour: ";
//     cin >> defect1 >> defect2 >> defect3;

//     cout << "Enter defect limits: ";
//     cin >> limit1 >> limit2 >> limit3;

//     cout << "Enter maintenance intervals: ";
//     cin >> maint1 >> maint2 >> maint3;

//     if (target <= 0 || shiftHours <= 0 ||
//         cap1 <= 0 || cap2 <= 0 || cap3 <= 0 ||
//         defect1 < 0 || defect2 < 0 || defect3 < 0 ||
//         defect1 > cap1 || defect2 > cap2 || defect3 > cap3 ||
//         limit1 < 0 || limit2 < 0 || limit3 < 0 ||
//         maint1 <= 0 || maint2 <= 0 || maint3 <= 0) {
//         cout << "Invalid input.\n";
//         return 0;
//     }

//     int defects1 = 0, defects2 = 0, defects3 = 0;
//     int usable = 0, totalDefects = 0, downtime = 0;
//     int active1 = 1, active2 = 1, active3 = 1;
//     int hour = 1;

//     while (hour <= shiftHours && usable < target) {
//         int madeThisHour = 0;

//         // Machine 1
//         if (active1 == 1) {
//             if (hour % maint1 == 0) {
//                 downtime++;
//             } else {
//                 defects1 += defect1;
//                 totalDefects += defect1;

//                 if (defects1 > limit1) {
//                     active1 = 0;
//                 } else {
//                     madeThisHour += cap1 - defect1;
//                 }
//             }
//         }

//         // Machine 2
//         if (active2 == 1) {
//             if (hour % maint2 == 0) {
//                 downtime++;
//             } else {
//                 defects2 += defect2;
//                 totalDefects += defect2;

//                 if (defects2 > limit2) {
//                     active2 = 0;
//                 } else {
//                     madeThisHour += cap2 - defect2;
//                 }
//             }
//         }

//         // Machine 3
//         if (active3 == 1) {
//             if (hour % maint3 == 0) {
//                 downtime++;
//             } else {
//                 defects3 += defect3;
//                 totalDefects += defect3;

//                 if (defects3 > limit3) {
//                     active3 = 0;
//                 } else {
//                     madeThisHour += cap3 - defect3;
//                 }
//             }
//         }

//         // Add this hour's usable production
//         usable += madeThisHour;

//         cout << "Hour " << hour
//              << " | Usable: " << usable
//              << " | Defects: " << totalDefects << "\n";

//         if (active1 == 0 && active2 == 0 && active3 == 0) {
//             cout << "All machines stopped.\n";
//             break;
//         }

//         hour++;
//     }

//     cout << "\nUsable products: " << usable;
//     cout << "\nTotal defects: " << totalDefects;
//     cout << "\nMachine maintenance downtime: " << downtime;

//     if (usable >= target) {
//         cout << "\nTarget achieved.\n";
//     } else {
//         cout << "\nTarget not achieved.\n";
//     }

//     return 0;
// }

// Logic: Each machine maintains its own cumulative defect counter. madeThisHour collects the usable production from active machines, and usable is updated once per hour. Here, a batch that causes a machine to exceed its defect limit is excluded from usable production, although its defects are counted.
