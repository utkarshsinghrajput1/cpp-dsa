// Question 5 — Warehouse Emergency Inventory System
// Problem statement
// A warehouse stores products A, B and C. Each day, some inventory expires, new stock arrives, and a customer order must be fulfilled.

// For this exercise, each day has one order. The order is fulfilled only if every required quantity is available. A fixed amount of stock expires at the beginning of each day.

#include <iostream>
using namespace std;

int main() {
    int stockA, stockB, stockC;
    int capacity, days;

    int expireA, expireB, expireC;

    cout << "Enter initial stock A, B, C: ";
    cin >> stockA >> stockB >> stockC;

    cout << "Enter total storage capacity: ";
    cin >> capacity;

    cout << "Enter daily expiry quantities A, B, C: ";
    cin >> expireA >> expireB >> expireC;

    cout << "Enter number of days: ";
    cin >> days;

    if (stockA < 0 || stockB < 0 || stockC < 0 ||
        capacity <= 0 ||
        stockA + stockB + stockC > capacity ||
        expireA < 0 || expireB < 0 || expireC < 0 ||
        days < 0) {
        cout << "Invalid input.\n";
        return 0;
    }

    int lostOrders = 0;
    int expiredTotal = 0;
    int day = 1;

    while (day <= days) {
        int deliveryA, deliveryB, deliveryC;
        int orderA, orderB, orderC;

        cout << "\nDay " << day << "\n";

        cout << "Enter deliveries A, B, C: ";
        cin >> deliveryA >> deliveryB >> deliveryC;

        cout << "Enter order quantities A, B, C: ";
        cin >> orderA >> orderB >> orderC;

        if (deliveryA < 0 || deliveryB < 0 ||
            deliveryC < 0 || orderA < 0 ||
            orderB < 0 || orderC < 0) {
            cout << "Invalid quantities. Try again.\n";
            continue;
        }

        // Expire old stock before deliveries arrive.
        int removedA = expireA;
        int removedB = expireB;
        int removedC = expireC;

        if (removedA > stockA) removedA = stockA;
        if (removedB > stockB) removedB = stockB;
        if (removedC > stockC) removedC = stockC;

        stockA -= removedA;
        stockB -= removedB;
        stockC -= removedC;

        expiredTotal += removedA + removedB + removedC;

        // Accept deliveries only within storage capacity.
        int space = capacity - (stockA + stockB + stockC);

        int acceptedA = deliveryA;
        if (acceptedA > space) acceptedA = space;
        stockA += acceptedA;
        space -= acceptedA;

        int acceptedB = deliveryB;
        if (acceptedB > space) acceptedB = space;
        stockB += acceptedB;
        space -= acceptedB;

        int acceptedC = deliveryC;
        if (acceptedC > space) acceptedC = space;
        stockC += acceptedC;

        // Fulfill the order only if all products exist.
        if (stockA >= orderA &&
            stockB >= orderB &&
            stockC >= orderC) {

            stockA -= orderA;
            stockB -= orderB;
            stockC -= orderC;

            cout << "Order fulfilled.\n";
        }
        else {
            lostOrders++;
            cout << "Order rejected: insufficient stock.\n";
        }

        cout << "Remaining stock: A=" << stockA
             << ", B=" << stockB
             << ", C=" << stockC << "\n";

        cout << "Storage used: "
             << stockA + stockB + stockC
             << "/" << capacity << "\n";

        day++;
    }

    cout << "\nExpired units: " << expiredTotal;
    cout << "\nRejected orders: " << lostOrders;
    cout << "\nFinal inventory: "
         << stockA << ", " << stockB << ", " << stockC << "\n";

    return 0;
}

// Important logic
// 1. Expiry is processed first.
// 2. Deliveries are accepted only up to the remaining storage capacity.
// 3. An order is fulfilled only if all three product quantities are available.
// 4. If any product is insufficient, the entire order is rejected and inventory remains unchanged by that order.
// Limitation: This model treats expiry as a fixed number of units expiring every day; it does not track individual batches or order deadlines. Those require a more detailed model.
