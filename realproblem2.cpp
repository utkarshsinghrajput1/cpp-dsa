// 2. Employee Overtime Salary Calculator
// Problem: N employees ke working hours aur hourly salary input lo. 40 hours se zyada kaam karne par extra hours ka payment 1.5 times rate se milega. Har employee ki salary aur total payroll print karo.
#include <iostream>
using namespace std;

int main() {
    int N, hours;
    double rate, salary, payroll = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> hours >> rate;

        if (hours > 40)
            salary = 40 * rate + (hours - 40) * rate * 1.5;
        else
            salary = hours * rate;

        cout << "Employee " << i << ": " << salary << endl;
        payroll = payroll + salary;
    }

    cout << "Total Payroll: " << payroll;
    return 0;
}