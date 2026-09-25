// 35. Coffee Vending Machine Coin Collector
// Problem: Ek coffee ki keemat Rs. 40 hai. 
// Machine me user tab tak Rs. 10 ke coins dalta hai jab tak total amount 40 ya usse zyada na ho jaye.
#include <iostream>
using namespace std;
int main() {
    int collected = 0;
    int price = 40;
    int coin = 10;
    while (collected < price) {
        collected += coin;
        cout << "Rs. " << coin << " inserted. Total: Rs. " << collected << endl;
    }
    cout << "Coffee dispensed! Enjoy." << endl;
    return 0;
}