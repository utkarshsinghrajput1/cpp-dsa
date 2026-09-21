// Q19. Game Lives and Score
// Write a C++ program using a while loop for a game. 
// The player starts with 3 lives and 0 score. 
// In every round, input 1 for a correct answer and 0 for a wrong answer. 
// A correct answer increases the score by 10, while a wrong answer decreases one life. 
// The game ends when all lives are lost or the user enters -1. 
// Display the final score and remaining lives.
// Single Logic Flow Chart
// START
//   ↓
// Initialize:
// lives = 3
// score = 0
//   ↓
// Input Answer
//   ↓
// Is answer = -1 OR lives = 0?
//   ├── YES → Display Final Score & Remaining Lives → STOP
//   │
//   └── NO
//        ↓
//    Is answer = 1?
//    ├── YES → score = score + 10
//    │
//    └── NO
//         ↓
//      Is answer = 0?
//      ├── YES → lives = lives - 1
//      │
//      └── NO → Print "Invalid Input"
//         ↓
//    Display Score & Lives
//         ↓
//    Is lives > 0?
//    ├── NO → Display Final Score & Remaining Lives → STOP
//    │
//    └── YES
//         ↓
//    Input Answer Again
//         ↓
//    Go back to:
//    Is answer = -1 OR lives = 0?

// Is question ka main logic
// Correct (1)
//     ↓
// Score + 10

// Wrong (0)
//     ↓
// Lives - 1

// -1
//     ↓
// Stop Game

// Lives = 0
//     ↓
// Stop Game

// Solution:
#include <iostream>
using namespace std;

int main()
{
    int lives = 3;          // [INITIALIZE] Player ke paas 3 lives
    int score = 0;          // [INITIALIZE] Starting score = 0
    int answer;             // [INPUT] User ka answer store karega

    cout << "Enter 1 for Correct, 0 for Wrong, -1 to Exit\n";
    cout << "Enter result: ";
    cin >> answer;          // [INPUT] First round ka result

    while (answer != -1 && lives > 0)
    {
        // [CONDITION] Jab tak -1 nahi hai aur lives > 0 hain

        if (answer == 1)
        {
            score = score + 10;
            // [WORK] Correct answer → score +10

            cout << "Correct! Score +10\n";
        }
        else if (answer == 0)
        {
            lives--;
            // [UPDATE] Wrong answer → 1 life decrease

            cout << "Wrong! One life lost\n";
        }
        else
        {
            cout << "Invalid input! Enter 1, 0 or -1\n";
        }

        cout << "Score = " << score << endl;
        cout << "Lives = " << lives << endl;

        // Agar lives abhi bhi available hain,
        // to next round ka input lenge
        if (lives > 0)
        {
            cout << "\nEnter result: ";
            cin >> answer;      // [INPUT] Next round
        }
    }

    cout << "\n===== GAME OVER =====\n";
    cout << "Final Score = " << score << endl;
    cout << "Remaining Lives = " << lives << endl;

    return 0;
}