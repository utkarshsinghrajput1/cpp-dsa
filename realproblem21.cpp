// 21. Student Attendance Eligibility
// Problem: N students ke total classes aur attended classes input lo. Attendance percentage 75% ya usse zyada hai toh student exam ke liye eligible hoga.
#include <iostream>
using namespace std;

int main() {
    int N, total, attended;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> total >> attended;

        if (total <= 0 || attended < 0 || attended > total) {
            cout << "Invalid Data" << endl;
        } else {
            double percentage = attended * 100.0 / total;

            cout << "Attendance: " << percentage << "%" << endl;

            if (percentage >= 75)
                cout << "Eligible" << endl;
            else
                cout << "Not Eligible" << endl;
        }
    }

    return 0;
}