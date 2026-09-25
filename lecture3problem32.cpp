// 32. Stock Price Drop Alert
// Problem: Ek stock ka initial price Rs. 500 hai. Market down hone par har ghante price Rs. 15 girta hai. 
// Jab tak price Rs. 400 ya usse kam na ho jaye, monitoring jari rakho.
#include <iostream>
using namespace std;
int main() {
    int stock_price = 500;
    int hours = 0;
    while (stock_price > 400) {
        hours++;
        stock_price -= 15;
        cout << "Hour " << hours << " -> Stock Price: Rs. " << stock_price << endl;
    }
    cout << "Buy Signal Triggered!" << endl;
    return 0;
}