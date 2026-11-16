// 25. Hospital Appointment Scheduling
// Problem: Hospital ke D doctors hain. Har doctor ke daily available slots S hain. P patients ko appointments deni hain. Nested loops se doctor-wise appointments allocate karo aur waiting patients count karo.
#include <iostream>
using namespace std;

int main() {
    int D, S, P;
    cin >> D >> S >> P;

    int assigned = 0;

    for (int doctor = 1; doctor <= D; doctor++) {
        int count = 0;

        for (int slot = 1; slot <= S; slot++) {
            if (assigned < P) {
                assigned++;
                count++;
            }
        }

        cout << "Doctor " << doctor
             << " Appointments: " << count << endl;
    }

    cout << "Assigned: " << assigned << endl;
    cout << "Waiting Patients: " << P - assigned;

    return 0;
}