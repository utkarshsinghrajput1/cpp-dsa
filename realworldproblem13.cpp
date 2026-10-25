// Problem 13: Examination Hall Seat Allocation
// Real-world question: 3 exam halls mein seats available hain. Har hall ki capacity 4 students hai. Total 10 students ko sequentially allocate karo. Pehle Hall 1, phir Hall 2, phir Hall 3 fill karo. Sab halls full ho jaayen toh students ko reject karo.

#include <iostream>
using namespace std;

int main() {
    int cap1 = 4;
    int cap2 = 4;
    int cap3 = 4;

    int hall1 = 0;
    int hall2 = 0;
    int hall3 = 0;

    int students = 10;
    int rejected = 0;

    for (int i = 1; i <= students; i++) {

        // Allocate to Hall 1 first
        if (hall1 < cap1) {
            hall1++;
            cout << "Student " << i << " -> Hall 1\n";
        }

        // If Hall 1 is full, try Hall 2
        else if (hall2 < cap2) {
            hall2++;
            cout << "Student " << i << " -> Hall 2\n";
        }

        // If Hall 1 and Hall 2 are full, try Hall 3
        else if (hall3 < cap3) {
            hall3++;
            cout << "Student " << i << " -> Hall 3\n";
        }

        // No seats left in any hall
        else {
            rejected++;
            cout << "Student " << i << " -> No seat available\n";
        }
    }

    cout << "\nFinal Hall Occupancy:\n";
    cout << "Hall 1: " << hall1 << "/" << cap1 << "\n";
    cout << "Hall 2: " << hall2 << "/" << cap2 << "\n";
    cout << "Hall 3: " << hall3 << "/" << cap3 << "\n";

    cout << "Rejected students: " << rejected << "\n";

    return 0;
}

// Important logic:
// - for loop students ko ek-ek karke allocate karta hai.
// - else if ki wajah se ek student sirf ek hall mein allocate hota hai.
// - Har hall ka occupancy counter alag maintain hota hai.
// - Is example mein 10 students hain aur 12 seats, isliye koi student reject nahi hoga.
