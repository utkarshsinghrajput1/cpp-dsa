// Problem 29: Factory Quality Reinspection
// Question: 3 product batches ke defect counts diye gaye hain. Critical defect count 5 ya usse zyada ho toh batch reject karo. Agar defects 2 se zyada hain lekin 5 se kam hain, toh har reinspection round mein defects 1 kam ho jaate hain. Maximum 3 rounds allowed hain.

#include <iostream>
using namespace std;

int main() {
    int defects1 = 4;
    int defects2 = 6;
    int defects3 = 3;

    int accepted = 0;
    int rejected = 0;

    // Process Batch 1
    if (defects1 >= 5) {
        rejected++;
        cout << "Batch 1 rejected: Critical defects\n";
    } else {
        int rounds = 0;

        while (defects1 > 2 && rounds < 3) {
            defects1--;
            rounds++;
        }

        if (defects1 <= 2) {
            accepted++;
            cout << "Batch 1 accepted after " << rounds << " rounds\n";
        } else {
            rejected++;
            cout << "Batch 1 rejected after reinspection\n";
        }
    }

    // Process Batch 2
    if (defects2 >= 5) {
        rejected++;
        cout << "Batch 2 rejected: Critical defects\n";
    } else {
        int rounds = 0;

        while (defects2 > 2 && rounds < 3) {
            defects2--;
            rounds++;
        }

        if (defects2 <= 2) {
            accepted++;
            cout << "Batch 2 accepted after " << rounds << " rounds\n";
        } else {
            rejected++;
            cout << "Batch 2 rejected after reinspection\n";
        }
    }

    // Process Batch 3
    if (defects3 >= 5) {
        rejected++;
        cout << "Batch 3 rejected: Critical defects\n";
    } else {
        int rounds = 0;

        while (defects3 > 2 && rounds < 3) {
            defects3--;
            rounds++;
        }

        if (defects3 <= 2) {
            accepted++;
            cout << "Batch 3 accepted after " << rounds << " rounds\n";
        } else {
            rejected++;
            cout << "Batch 3 rejected after reinspection\n";
        }
    }

    cout << "\nAccepted batches: " << accepted << "\n";
    cout << "Rejected batches: " << rejected << "\n";

    return 0;
}

// Important logic:
// - Critical-defect test reinspection se pehle hota hai.
// - while loop maximum 3 reinspection rounds allow karta hai.
// - Defects acceptable limit tak aa jaayen toh batch accepted hota hai.
// - Is simulation mein reinspection se defects reduce hone ko assumed model maana gaya hai.
