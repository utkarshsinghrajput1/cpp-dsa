// 40. Electronic Component Assembly
// Problem: Ek electronic device banane ke liye 3 resistors, 2 capacitors aur 1 processor chahiye. N devices banane ke liye available component quantities input lo. Calculate karo maximum kitne complete devices ban sakte hain.
#include <iostream>
using namespace std;

int main() {
    int resistors, capacitors, processors;
    cin >> resistors >> capacitors >> processors;

    int devices = 0;

    while (resistors >= 3 &&
           capacitors >= 2 &&
           processors >= 1) {

        resistors = resistors - 3;
        capacitors = capacitors - 2;
        processors = processors - 1;

        devices++;
    }

    cout << "Devices Manufactured: " << devices << endl;
    cout << "Remaining Resistors: " << resistors << endl;
    cout << "Remaining Capacitors: " << capacitors << endl;
    cout << "Remaining Processors: " << processors;

    return 0;
}