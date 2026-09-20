// Q14. Game Health System
// Write a C++ program using a while loop for a game in which the player's initial health is 100. Continuously accept damage values. 
// Subtract the damage from the player's health. 
// The game should stop when the health becomes zero or negative. 
// Finally, display "Game Over" and the remaining health.
// Hume 3 cheezein chahiye:
// int health = 100;   // [INITIALIZE] Player ki starting health
// int damage;         // [INPUT] Har round ka damage
// Logic:
// Player ki health 100 se start hoti hai. User damage input karega.
// Har damage ko health me se subtract karna hai.
// Jab health 0 ya negative ho jaye, game over ho jayega. End me "Game Over" aur remaining health print karni hai.
// Har round:

// Damage input lo
// Health se damage minus karo
// Health print karo
// Agar health 0 ya less ho gayi → game over
// Soltion:
#include <iostream>
using namespace std;

int main()
{
    int health = 100;        // [INITIALIZE] Starting health = 100
    int damage;              // [INPUT] Damage store karne ke liye

    cout << "Player Health = " << health << endl;

    while (health > 0)      // [CONDITION] Jab tak health > 0 hai
    {
        cout << "Enter damage: ";
        cin >> damage;      // [INPUT] Damage lo

        health = health - damage;   // [WORK] Health se damage subtract karo

        cout << "Current Health = " << health << endl; // [OUTPUT]

        if (health <= 0)    // [CHECK] Health 0 ya less ho gayi?
        {
            cout << "GAME OVER!" << endl;
            break;          // [STOP] Loop ko stop karo
        }
    }

    return 0;
}