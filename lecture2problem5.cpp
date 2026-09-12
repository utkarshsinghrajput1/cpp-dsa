/* This comprehensive problem combines addition, subtraction, multiplication, integer division, the modulo operator, operator precedence, and type casting into one single realistic scenario.
Problem Statement: Smart ATM Denomination & Receipt Generator
Write a C++ program that takes a 4-digit withdrawal amount and a transaction fee percentage (as an integer or float) from the user.
Your program must perform and output the following calculations using arithmetic operators:
Total Deduction: Add a flat bank charge of $15 and calculate the percentage-based tax/fee using division and multiplication, adding it to the withdrawal amount.
Denomination Breakdown: Break down the original 4-digit amount into the minimum number of currency notes ($500, $100, $50, $10) and remaining loose coins using / and %.
Digit Extraction & Verification: Extract the first and last digits of the 4-digit amount and add them together to generate a security verification code.
Precise Average per Digit: Calculate the exact average value of the 4 individual digits using explicit typecasting to avoid integer division loss. */

// Solution:
#include <iostream>
using namespace std;

int main() {
    // ------------------------------------------------------------------------
    // VARIABLES INITIALIZATION
    // ------------------------------------------------------------------------
    int amount;        // We use 'int' because ATM withdrawals and notes are whole numbers.
    double taxRate;    // We use 'double' because tax percentages can be in decimals (e.g., 4.5%).

    // Taking user input
    cout << "Enter 4-digit withdrawal amount (e.g., 2876): ";
    cin >> amount;
    cout << "Enter tax percentage rate (e.g., 5 for 5%): ";
    cin >> taxRate;

    // ------------------------------------------------------------------------
    // STEP 1: TOTAL COST CALCULATION (Using +, *, /)
    // ------------------------------------------------------------------------
    int flatFee = 15; // Flat bank charge in dollars
    
    /* 
       WHY MULTIPLICATION (*) AND DIVISION (/) HERE?
       To find 5% of 2876, the math is (2876 * 5) / 100.
       We divide by '100.0' (not 100) so that C++ treats the calculation as 
       floating-point math. If we do integer division, the fractional tax part is lost.
    */
    double percentageFee = (amount * taxRate) / 100.0; 

    /* 
       WHY ADDITION (+) HERE?
       We use the '+' operator to sum up the base amount, fixed charges, 
       and calculated tax to get the final deducted money.
    */
    double totalDeduction = amount + flatFee + percentageFee;


    // ------------------------------------------------------------------------
    // STEP 2: DENOMINATION BREAKDOWN (The Ultimate / and % Game)
    // ------------------------------------------------------------------------
    /* 
       Suppose amount is 2876.
       
       WHY DIVISION (/) FOR NOTES?
       Integer division drops decimals. 2876 / 500 = 5.752, but since both are integers, 
       C++ throws away '.752' and gives exactly 5. This tells us we need 5 notes of $500.
       
       WHY MODULO (%) FOR REMAINDER?
       The '%' operator gives only the remainder. 2876 % 500 = 376. 
       This 376 is the left-over amount that cannot be paid using $500 notes.
    */
    int notes500 = amount / 500;  // Example: 2876 / 500 = 5 notes
    int rem500 = amount % 500;    // Example: 2876 % 500 = $376 remaining

    // Now we break down the remaining $376 using $100 notes
    int notes100 = rem500 / 100;  // Example: 376 / 100 = 3 notes
    int rem100 = rem500 % 100;    // Example: 376 % 100 = $76 remaining

    // Now we break down the remaining $76 using $50 notes
    int notes50 = rem100 / 50;    // Example: 76 / 50 = 1 note
    int rem50 = rem100 % 50;      // Example: 76 % 50 = $26 remaining

    // Now we break down the remaining $26 using $10 notes
    int notes10 = rem50 / 10;     // Example: 26 / 10 = 2 notes
    int coins = rem50 % 10;       // Example: 26 % 10 = 6 coins left (cannot be made into notes)


    // ------------------------------------------------------------------------
    // STEP 3: DIGIT EXTRACTION (Using Tricky / and % Rules)
    // ------------------------------------------------------------------------
    /* 
       TRICK 1: Any integer modulo 10 (% 10) ALWAYS gives the last digit.
       Example: 2876 % 10 = 6.
       
       TRICK 2: Since it is a guaranteed 4-digit number, dividing by 1000 (/ 1000) 
       removes the last three digits entirely due to integer truncation.
       Example: 2876 / 1000 = 2.
    */
    int lastDigit = amount % 10;    // Extracts 6
    int firstDigit = amount / 1000; // Extracts 2
    int securityCode = firstDigit + lastDigit; // 2 + 6 = 8


    // ------------------------------------------------------------------------
    // STEP 4: PRECISE AVERAGE (Typecasting Concepts)
    // ------------------------------------------------------------------------
    /* 
       Let's isolate all 4 digits of 2876 one by one:
       d1 (Thousands): 2876 / 1000 = 2
       d2 (Hundreds):  2876 / 100 = 28 -> then 28 % 10 = 8
       d3 (Tens):      2876 / 10  = 287 -> then 287 % 10 = 7
       d4 (Units):     2876 % 10 = 6
    */
    int d1 = amount / 1000;         
    int d2 = (amount / 100) % 10;   
    int d3 = (amount / 10) % 10;    
    int d4 = amount % 10;           
    
    /* 
       WHY TYPECASTING (double) HERE?
       The sum of digits is 2 + 8 + 7 + 6 = 23 (an integer).
       There are 4 digits (an integer).
       If we do 23 / 4, C++ will do integer division and output 5 instead of 5.75.
       
       By adding '(double)' in front of the sum, we forcefully convert 23 into 23.0.
       Now, 23.0 / 4.0 gives a precise mathematical result: 5.75.
    */
    double digitAverage = (double)(d1 + d2 + d3 + d4) / 4.0;


    // ------------------------------------------------------------------------
    // DISPLAYING THE OUTPUT RECEIPT
    // ------------------------------------------------------------------------
    cout << "\n===============================" << endl;
    cout << "       ATM TRANSACTION RECEIPT  " << endl;
    cout << "===============================" << endl;
    cout << "Original Request: $" << amount << endl;
    cout << "Total Bank Deduction: $" << totalDeduction << " (Includes $15 fee + tax)" << endl;
    cout << "-------------------------------" << endl;
    cout << "Dispensed Currency:" << endl;
    cout << "  $500 Notes : " << notes500 << endl;
    cout << "  $100 Notes : " << notes100 << endl;
    cout << "  $50 Notes  : " << notes50 << endl;
    cout << "  $10 Notes  : " << notes10 << endl;
    cout << "  Loose Coins: " << coins << endl;
    cout << "-------------------------------" << endl;
    cout << "Security Pin (1st + Last Digit): " << securityCode << endl;
    cout << "Mathematical Average of Digits : " << digitAverage << endl;
    cout << "===============================" << endl;

    return 0;
}
