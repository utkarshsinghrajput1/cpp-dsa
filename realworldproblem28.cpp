// Problem 28: Toll Plaza Traffic and Revenue Controller
// Question: 3 toll lanes ki capacities alag hain. Har lane mein kitne vehicles process ho sakte hain, aur har vehicle ka toll ₹100 hai. 5 vehicles ko shortest queue wali lane par assign karo, provided lane open ho.

#include <iostream>
using namespace std;

int main() {
    int lane1Queue = 4;
    int lane2Queue = 2;
    int lane3Queue = 3;

    int lane1Open = 1;
    int lane2Open = 1;
    int lane3Open = 0; // Lane 3 is closed

    int revenue = 0;
    int rejected = 0;
    int vehicles = 5;

    for (int i = 1; i <= vehicles; i++) {
        // Select the shortest queue among open lanes
        if (lane1Open == 1 &&
            (lane2Open == 0 || lane1Queue <= lane2Queue) &&
            (lane3Open == 0 || lane1Queue <= lane3Queue)) {
            lane1Queue++;
            revenue += 100;
            cout << "Vehicle " << i << " -> Lane 1\n";
        }
        else if (lane2Open == 1 &&
                 (lane1Open == 0 || lane2Queue <= lane1Queue) &&
                 (lane3Open == 0 || lane2Queue <= lane3Queue)) {
            lane2Queue++;
            revenue += 100;
            cout << "Vehicle " << i << " -> Lane 2\n";
        }
        else if (lane3Open == 1) {
            lane3Queue++;
            revenue += 100;
            cout << "Vehicle " << i << " -> Lane 3\n";
        }
        else {
            rejected++;
            cout << "Vehicle " << i << " could not be assigned\n";
        }
    }

    cout << "\nLane 1 queue: " << lane1Queue << "\n";
    cout << "Lane 2 queue: " << lane2Queue << "\n";
    cout << "Lane 3 queue: " << lane3Queue << "\n";
    cout << "Revenue: Rs. " << revenue << "\n";
    cout << "Unassigned vehicles: " << rejected << "\n";

    return 0;
}
// Important logic:
// - laneOpen flag decide karta hai ki lane available hai ya nahi.
// - Closed lane ko queue comparison mein ignore kiya jaata hai.
// - Successful assignment par revenue ₹100 increase hota hai.
// - Yeh simplified model queue length ko waiting vehicles ka estimate maanta hai; actual lane capacity aur processing speed separately model karni hogi.
