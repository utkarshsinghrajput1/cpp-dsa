// Problem 36: Hospital Medical Oxygen Allocation
// Question: 3 hospital wards ki oxygen demands 40, 30 aur 50 units hain. Total supply 100 units hai. Ward 1 ko sabse pehle oxygen do, phir Ward 2, phir Ward 3. Demand poori na ho sake toh shortage report karo.

#include <iostream>
using namespace std;

int main() {
    int supply = 100;

    int demand1 = 40;
    int demand2 = 30;
    int demand3 = 50;

    int given1 = 0;
    int given2 = 0;
    int given3 = 0;

    // Ward 1 has highest priority
    if (supply >= demand1) {
        given1 = demand1;
        supply -= given1;
    } else {
        given1 = supply;
        supply = 0;
    }

    // Ward 2 receives the remaining oxygen
    if (supply >= demand2) {
        given2 = demand2;
        supply -= given2;
    } else {
        given2 = supply;
        supply = 0;
    }

    // Ward 3 receives whatever is still available
    if (supply >= demand3) {
        given3 = demand3;
        supply -= given3;
    } else {
        given3 = supply;
        supply = 0;
    }

    cout << "Ward 1 received: " << given1
         << ", shortage: " << demand1 - given1 << "\n";

    cout << "Ward 2 received: " << given2
         << ", shortage: " << demand2 - given2 << "\n";

    cout << "Ward 3 received: " << given3
         << ", shortage: " << demand3 - given3 << "\n";

    cout << "Remaining supply: " << supply << "\n";

    return 0;
}

// Important logic:
// - Har ward ko priority order mein supply milti hai.
// - Supply demand se kam ho toh available amount assign hota hai aur balance zero ho jaata hai.
// - Shortage = demand − received supply.
// - Real medical oxygen distribution mein clinical urgency aur minimum safe requirements ko simple fixed order se replace nahi karna chahiye.
