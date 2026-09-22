// MASTER WHILE-LOOP FLOWCHART
            //              START
            //                ↓
            //       INITIALIZE VARIABLES
            //                ↓
            //   ┌────────────────────────┐
            //   │ counter = 0            │
            //   │ total = 0              │
            //   │ previous = initial     │
            //   │ score/lives/balance... │
            //   └────────────────────────┘
            //                ↓
            //         TAKE INPUT
            //                ↓
            //   ┌────────────────────────┐
            //   │  STOP CONDITION?       │
            //   │  -1 / 0 / exit /       │
            //   │  limit reached /       │
            //   │  lives = 0 etc.        │
            //   └────────────────────────┘
            //         ↓              ↓
            //       YES              NO
            //         ↓               ↓
            //   FINAL OUTPUT      CHECK INPUT
            //         ↓               ↓
            //       STOP       ┌─────────────────┐
            //                  │ IF / ELSE IF    │
            //                  │ condition       │
            //                  └─────────────────┘
            //                    ↓      ↓
            //                   YES     NO
            //                    ↓       ↓
            //               PERFORM WORK
            //                    ↓
            //         ┌─────────────────────┐
            //         │ UPDATE VARIABLES    │
            //         │                     │
            //         │ total += value      │
            //         │ count++             │
            //         │ lives--             │
            //         │ score += 10         │
            //         │ previous = current  │
            //         └─────────────────────┘
            //                    ↓
            //              TAKE INPUT AGAIN
            //                    ↓
            //         ──────── REPEAT ────────
            //                    ↑
            //                    │
            //          STOP CONDITION CHECK

// Ab isko question types se connect kar
// 1. Restaurant / Menu System
// 

// 2. Electricity Meter
// Input new reading
//        ↓
// Reading = -1?
//  ├─ YES → Total Consumption → STOP
//  └─ NO
//        ↓
// units = new - previous
//        ↓
// total += units
//        ↓
// previous = new
//        ↓
// Input Again

// 3. Game Lives & Score
// Input 1 / 0
//      ↓
// -1 OR lives = 0?
//  ├─ YES → Final Score/Lives → STOP
//  └─ NO
//       ↓
//    Correct?
//    ├─ YES → score += 10
//    └─ NO  → lives--
//       ↓
//    Input Again

// 4. Counter Type Questions
// Input number
//     ↓
// Stop condition?
//     ↓ NO
// Number even?
//  ├─ YES → count++
//  └─ NO
//     ↓
// Input Again
//     ↓
// Repeat
//     ↓
// Final count

// 5. Accumulator / Total Type
// Example: "Keep accepting numbers and calculate their sum until -1."
// Input number
//     ↓
// number = -1?
//  ├─ YES → Print total → STOP
//  └─ NO
//       ↓
//    total = total + number
//       ↓
//    Input Again
//       ↓
//     Repeat

// 6. Condition / Classification Type
// Example: Temperature:
// Input temperature
//        ↓
// Stop value?
//        ↓ NO
//        ↓
// temperature < 0?
//  ├─ YES → Very Cold
//  └─ NO
//       ↓
// temperature <= 20?
//  ├─ YES → Cold
//  └─ NO
//       ↓
// temperature <= 35?
//  ├─ YES → Normal
//  └─ NO → Hot
//       ↓
// Input Again
    //   ↓
// Repeat

// Yahan mainly if / else if / else important hai.

// Sabse Important Universal Formula
// Bhai, exam mein koi bhi while-loop scenario aaye, pehle ye 5 cheezein identify kar:
// 1. INITIALIZE
//       ↓
// 2. INPUT
//       ↓
// 3. STOP CONDITION
//       ↓
// 4. WORK / IF-ELSE
//       ↓
// 5. UPDATE
//       ↓
//    INPUT AGAIN
//       ↓
//    REPEAT



// Aur ye keywords dekhte hi samajh jaana:
// | Question mein word           | Logic                |
// | ---------------------------- | -------------------- |
// | **total / sum**              | `total += value`     |
// | **number of / count**        | `count++`            |
// | **until -1**                 | `while(input != -1)` |
// | **until 0**                  | `while(choice != 0)` |
// | **correct/wrong**            | `if/else`            |
// | **lives decrease**           | `lives--`            |
// | **score increase**           | `score += 10`        |
// | **balance increase**         | `balance += amount`  |
// | **balance decrease**         | `balance -= amount`  |
// | **previous/current reading** | `current - previous` |
// | **menu**                     | `while + if/else`    |
// | **maximum attempts**         | counter + condition  |
// | **limit reached**            | condition + `break`  |
// | **largest/smallest**         | tracker variable     |
// | **average**                  | `total / count`      |

// One-line trick
// QUESTION
//    ↓
// Kya repeat ho raha hai?
//    ↓
// WHILE
//    ↓
// Kab rukega?
//    ↓
// CONDITION
//    ↓
// Har baar kya kaam hoga?
//    ↓
// WORK
//    ↓
// Kya change hoga?
//    ↓
// UPDATE