// 26. Examination Result and Grade Distribution
// Problem: N students ke marks input lo. 90+ par A grade, 75+ par B, 60+ par C, 40+ par D, otherwise fail. Har grade mein kitne students hain, calculate karo.
#include <iostream>
using namespace std;

int main() {
    int N, marks;
    int A = 0, B = 0, C = 0, D = 0, F = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> marks;

        if (marks < 0 || marks > 100) {
            cout << "Invalid Marks" << endl;
        } else if (marks >= 90) {
            A++;
        } else if (marks >= 75) {
            B++;
        } else if (marks >= 60) {
            C++;
        } else if (marks >= 40) {
            D++;
        } else {
            F++;
        }
    }

    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;
    cout << "D: " << D << endl;
    cout << "Fail: " << F;

    return 0;
}