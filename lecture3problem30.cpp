// 30. Digital Wallet Top-up for Cart
// Problem: Tumhe ek item kharidna hai jiska price Rs. 1,500 hai. 
// Tumhare wallet me shuru me Rs. 200 hain. 
// Tum har baar Rs. 300 add karte ho jab tak price cover na ho jaye.
#include <iostream>
using namespace std;
int main() {
    int wallet = 200;
    int item_price = 1500;
    int add_amount = 300;
    int times = 0;
    while (wallet < item_price) {
        times++;
        wallet += add_amount;
        cout << "Top-up " << times << " -> Wallet balance: Rs. " << wallet << endl;
    }
    cout << "Purchase successful!" << endl;
    return 0;
}