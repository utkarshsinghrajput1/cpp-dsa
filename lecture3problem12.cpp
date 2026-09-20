// Q12. Movie Ticket Booking
// A cinema has 50 seats available. Write a C++ program using a while loop that continuously accepts the number of tickets a customer wants to book.
//  If enough seats are available, confirm the booking and reduce the available seats.
//  If not, display "Not Enough Seats". Stop when the user enters 0.
//  Finally, display total tickets sold and remaining seats.
// Soltion:
// Problem

// Cinema me 50 seats available hain. User batayega ki kitni tickets book karni hain.

// Agar seats available hain → booking successful
// Agar requested tickets available seats se zyada hain → "Not Enough Seats"
// 0 → booking stop
// End me total tickets sold aur remaining seats print karni hain.
#include <iostream>
using namespace std;

int main()
{
    int seats = 50;              // [INITIALIZATION] Starting available seats
    int tickets;                 // [INPUT] User kitni tickets chahta hai
    int totalSold = 0;           // [COUNTER] Total tickets sold

    cout << "Enter number of tickets (0 to stop): ";
    cin >> tickets;              // [INPUT] First ticket request

    while (tickets != 0)         // [CONDITION] Jab tak user 0 nahi deta
    {
        if (tickets <= seats)    // [CHECK] Kya enough seats available hain?
        {
            seats = seats - tickets;     // [UPDATE] Available seats reduce

            totalSold = totalSold + tickets; // [UPDATE] Sold tickets increase

            cout << "Booking Successful!\n";
        }
        else
        {
            cout << "Not Enough Seats!\n";
        }

        cout << "Remaining Seats = " << seats << "\n";

        cout << "Enter number of tickets (0 to stop): ";
        cin >> tickets;          // [UPDATE] Next ticket request
    }

    cout << "\nTotal Tickets Sold = " << totalSold << endl;
    cout << "Remaining Seats = " << seats << endl;

    return 0;
}