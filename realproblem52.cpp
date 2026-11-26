// 52. International Currency Exchange Reconciliation
// Problem: An exchange centre processes multiple customer transactions. Each customer exchanges money from one currency to another. The exchange rate and service fee differ by transaction.

// Calculate the converted amount, service fee and total amount received by each customer, along with the total amount distributed.
#include <iostream>    
using namespace std;

int main()
{
    int customers;
    double totalDistributed = 0;

    cout << "Enter customers: ";
    cin >> customers;

    for (int i = 1; i <= customers; i++)
    {
        double amount, rate, feePercent;

        cout << "\nAmount: ";
        cin >> amount;

        cout << "Exchange rate: ";
        cin >> rate;

        cout << "Service fee percentage: ";
        cin >> feePercent;

        double converted = amount * rate;
        double fee = converted * feePercent / 100;
        double received = converted - fee;

        totalDistributed += received;

        cout << "Converted: " << converted;
        cout << "\nFee: " << fee;
        cout << "\nReceived: " << received << endl;
    }

    cout << "\nTotal distributed: "
         << totalDistributed;

    return 0;
}