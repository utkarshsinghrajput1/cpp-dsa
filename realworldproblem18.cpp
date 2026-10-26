// Problem 18: E-Commerce Order Packing Scheduler
// Question: Do packing stations hain. Station 1 ko 3 minutes aur Station 2 ko 2 minutes per order lagte hain. Total 5 orders ko least busy available station par assign karo. Agar dono busy hain, next station free hone tak time advance karo.

#include <iostream>
using namespace std;

int main() {
    int station1Free = 0;
    int station2Free = 0;

    int station1Orders = 0;
    int station2Orders = 0;

    int time = 0;
    int orders = 5;

    for (int i = 1; i <= orders; i++) {
        // Find the next time at which at least one station is free
        if (station1Free > time && station2Free > time) {
            if (station1Free < station2Free)
                time = station1Free;
            else
                time = station2Free;
        }

        // Assign to Station 1 if it is free and no later than Station 2
        if (station1Free <= time && station1Free <= station2Free) {
            cout << "Order " << i << " -> Station 1 at " << time << "\n";
            station1Free = time + 3;
            station1Orders++;
        }
        else {
            cout << "Order " << i << " -> Station 2 at " << time << "\n";
            station2Free = time + 2;
            station2Orders++;
        }
    }

    cout << "\nStation 1 orders: " << station1Orders << "\n";
    cout << "Station 2 orders: " << station2Orders << "\n";
    cout << "All orders scheduled by minute: "
         << (station1Free > station2Free ? station1Free : station2Free)
         << "\n";

    return 0;
}

// Important logic:
// - station1Free aur station2Free next available time store karte hain.
// - Dono busy hon toh time ko earliest free time tak advance karte hain.
// - Station ki processing duration uske free time mein add hoti hai.
// - Is simplified scheduler mein deadlines aur express priority include nahi hain.
