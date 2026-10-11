// Challenge: Sierpiński Triangle using Bitwise Logic
// Hard · Advanced
// 1. Problem statement
// Tumhe ek integer N diya jayega, jo \(2\) ki power hoga. Tumhe exactly N rows ka ek fractal pattern print karna hai.
// Rules:
// 1. Pattern ki har row mein positions \(0\) se \(r\) tak consider karo, jahan r row number hai aur first row 0 se start hoti hai.
// 2. Har position par * print karo agar us position ka corresponding binomial coefficient odd hai.
// 3. Agar coefficient even hai, toh us jagah space print karo.
// 4. Pattern centered hona chahiye.
// 5. Challenge: Pascal's Triangle ke numbers calculate nahi karne, factorial use nahi karna aur recursion use nahi karni. Bitwise logic se decide karo ki star kahan aayega.

// Input:
// 8

// Expected output:
//        *
//       * *
//      *   *
//     * * * *
//    *       *
//   * *     * *
//  *   *   *   *
// * * * * * * * *

// Ye Sierpiński Triangle ka pattern hai. Iski interesting baat ye hai ki tumhe bade numbers calculate karne ki zaroorat nahi hai.

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    // N must be a power of 2 and within a practical output limit
    if (n < 1 || n > 1024 || (n & (n - 1)) != 0) {
        cout << "N must be a power of 2 between 1 and 1024\n";
        return 0;
    }

    for (int r = 0; r < n; r++) {

        // Create one centered row
        string line(2 * n - 1, ' ');

        for (int c = 0; c <= r; c++) {

            // Star appears when every set bit of c
            // is also set in r
            if ((r & c) == c) {
                int position = n - 1 - r + 2 * c;
                line[position] = '*';
            }
        }

        cout << line << '\n';
    }

    return 0;
}


// iska pura explanation ache se ye niche he(ye bhadiya question he)

/*
====================================================================
       SIERPINSKI TRIANGLE PATTERN - COMPLETE C++ NOTES
====================================================================

TOPIC:
Advanced Pattern Printing using Bitwise AND and Binary Logic

DIFFICULTY:
Advanced

CONCEPTS USED:
1. Nested loops
2. Binary number representation
3. Bitwise AND (&)
4. Pascal's Triangle
5. Mathematical properties of odd and even numbers
6. String manipulation
7. Pattern alignment
8. Power of 2 checking

====================================================================
1. PROBLEM STATEMENT
====================================================================

You are given an integer N.

Print a centered Sierpinski Triangle consisting of N rows.

CONDITIONS:

1. N must be a power of 2 between 1 and 1024.
2. Row numbering starts from 0.
3. Column numbering also starts from 0.
4. Print '*' when the corresponding Pascal Triangle
   coefficient is odd.
5. Leave a blank space when the coefficient is even.
6. Do not calculate Pascal Triangle coefficients directly.
7. Use bitwise logic to determine the positions of stars.

INPUT:
8

EXPECTED OUTPUT:

       *
      * *
     *   *
    * * * *
   *       *
  * *     * *
 *   *   *   *
* * * * * * * *

IMPORTANT:
The spaces before the stars are important for centering.
The spaces between stars are also important for the shape.

====================================================================
2. WHAT IS SIERPINSKI TRIANGLE?
====================================================================

Sierpinski Triangle is a fractal pattern.

We can generate its star positions by observing the odd
and even numbers in Pascal's Triangle.

First, look at Pascal's Triangle:

Row 0:                 1
Row 1:               1   1
Row 2:             1   2   1
Row 3:           1   3   3   1
Row 4:         1   4   6   4   1
Row 5:       1   5  10  10   5   1
Row 6:     1   6  15  20  15   6   1
Row 7:   1   7  21  35  35  21   7   1

RULE:

Odd number  -> Print '*'
Even number -> Leave a blank space

For example:

Row 2 contains:

1  2  1

Here, 1 is odd, 2 is even, and 1 is odd.

Therefore, its star pattern is:

*   *

Similarly, row 4 contains:

1  4  6  4  1

Only the first and last numbers are odd.

Therefore, its star pattern is:

*       *

If we apply the same rule to every row, we obtain
the Sierpinski Triangle.

PROBLEM:
How can we identify odd and even coefficients without
calculating every number in Pascal's Triangle?

ANSWER:
Use the bitwise condition:

             (r & c) == c

This is the main trick of this problem.

====================================================================
3. WHAT IS A BINARY NUMBER?
====================================================================

Computers represent numbers using binary digits:
0 and 1.

Examples:

Decimal    Binary
-------    ------
0          000
1          001
2          010
3          011
4          100
5          101
6          110
7          111

For this problem:

r = Current row number
c = Current column number

We compare the binary representations of r and c.

Example:

r = 5

Binary representation of 5 is:

101

c = 3

Binary representation of 3 is:

011

These binary numbers are used in the bitwise condition.

====================================================================
4. UNDERSTANDING THE BITWISE AND (&) OPERATOR
====================================================================

The & operator compares two binary numbers bit by bit.

RULE:

0 & 0 = 0
0 & 1 = 0
1 & 0 = 0
1 & 1 = 1

In simple words:

The result bit is 1 only when both corresponding bits
are 1. Otherwise, the result bit is 0.

EXAMPLE 1:

       101    Decimal 5
     & 011    Decimal 3
       ---
       001    Decimal 1

Therefore:

5 & 3 = 1

EXAMPLE 2:

       101    Decimal 5
     & 100    Decimal 4
       ---
       100    Decimal 4

Therefore:

5 & 4 = 4

Now we use this concept to decide where stars should appear.

====================================================================
5. THE MOST IMPORTANT CONDITION
====================================================================

             if ((r & c) == c)

This condition determines whether we print a star.

If the condition is TRUE:
    Place '*' at the current position.

If the condition is FALSE:
    Leave the position as a space.

Here:
r = Row number
c = Column number

LET US UNDERSTAND THIS WITH ROW 5.

Row number:

r = 5 = 101 in binary

Now check different column numbers.

CASE 1: c = 0

r = 101
c = 000
    ---
AND 000

r & c = 0
c     = 0

Both values are equal.

Therefore, print '*'.

CASE 2: c = 1

r = 101
c = 001
    ---
AND 001

r & c = 1
c     = 1

Both values are equal.

Therefore, print '*'.

CASE 3: c = 2

r = 101
c = 010
    ---
AND 000

r & c = 0
c     = 2

Both values are NOT equal.

Therefore, leave a blank space.

CASE 4: c = 3

r = 101
c = 011
    ---
AND 001

r & c = 1
c     = 3

Both values are NOT equal.

Therefore, leave a blank space.

CASE 5: c = 4

r = 101
c = 100
    ---
AND 100

r & c = 4
c     = 4

Both values are equal.

Therefore, print '*'.

CASE 6: c = 5

r = 101
c = 101
    ---
AND 101

r & c = 5
c     = 5

Both values are equal.

Therefore, print '*'.

CONCLUSION:

For row 5, stars appear at columns:

0, 1, 4, 5

The resulting row looks like this:

* *     * *

This is how binary logic determines the pattern.

====================================================================
6. WHY DOES THIS MATHEMATICAL TRICK WORK?
====================================================================

Every position (r, c) in Pascal's Triangle corresponds
to the binomial coefficient:

                 C(r, c)

We do not need to calculate this coefficient.

A mathematical result called Lucas's theorem tells us
that, for Pascal's Triangle, C(r, c) is odd exactly when
every binary 1-bit in c is also a 1-bit in r.

The condition:

                 (r & c) == c

checks precisely this property.

EXAMPLE:

r = 5 = 101
c = 4 = 100

Every 1-bit of c also appears in r.

Therefore, the coefficient is odd, so print '*'.

ANOTHER EXAMPLE:

r = 5 = 101
c = 3 = 011

The middle bit of c is 1, but the corresponding bit in r
is 0.

Therefore, the coefficient is even, so leave a space.

IMPORTANT:
We do not generate Pascal Triangle's actual numbers.
We only determine whether each coefficient is odd or even.

This saves us from calculating large coefficients.

====================================================================
7. HOW DO WE CENTER THE PATTERN?
====================================================================

Suppose:

N = 8

The width of each row is:

              2 * N - 1

For N = 8:

              2 * 8 - 1 = 15

So we create a string containing 15 spaces.

                 string line(2 * n - 1, ' ');

Every star is then placed at its correct index.

The position formula is:

          position = n - 1 - r + 2 * c

Understand each part:

PART 1:
          n - 1 - r

This determines how far the row starts from the left.

As r increases, the starting position moves left.

PART 2:
          2 * c

This moves to the next possible star position.
We move by 2 because we want one character of space
between consecutive star positions.

EXAMPLE:

N = 8
r = 2

Starting position:

8 - 1 - 2 = 5

Possible positions:

c = 0:
position = 5 + 2 * 0 = 5

c = 1:
position = 5 + 2 * 1 = 7

c = 2:
position = 5 + 2 * 2 = 9

However, we place stars only when:

(r & c) == c

For row 2:

r = 2 = 010

c = 0 = 000
2 & 0 = 0  -> Star

c = 1 = 001
2 & 1 = 0  -> Space

c = 2 = 010
2 & 2 = 2  -> Star

Therefore, the row contains stars at positions 5 and 9.

The visible result is:

     *   *

====================================================================
8. CHECKING WHETHER N IS A POWER OF 2
====================================================================

The problem requires N to be a power of 2.

Examples of valid inputs:

1, 2, 4, 8, 16, 32, 64, ...

Why?

A positive power of 2 has exactly one 1-bit in binary.

Example:

8     = 1000
8 - 1 = 0111

Now perform bitwise AND:

       1000
     & 0111
       ----
       0000

The result is zero.

Therefore, 8 is a power of 2.

Now consider 6:

6     = 0110
6 - 1 = 0101

       0110
     & 0101
       ----
       0100

The result is not zero.

Therefore, 6 is not a power of 2.

The C++ condition is:

        (n & (n - 1)) != 0

If it is true, N is not a power of 2.

We also reject N values below 1 and above 1024.

====================================================================
9. COMPLETE C++ CODE WITH EXPLANATION
====================================================================

*/

// #include <iostream>
// #include <string>
// using namespace std;

// int main() {

    // STEP 1:
    // Read the number of rows from the user.
    // int n;
    // cin >> n;

    // STEP 2:
    // Validate the input.
    //
    // n must be between 1 and 1024.
    // Also, n must be a power of 2.
    //
    // If n is not valid, print an error and stop.
    // if (n < 1 || n > 1024 || (n & (n - 1)) != 0) {
    //     cout << "N must be a power of 2 between 1 and 1024\n";
    //     return 0;
    // }

    // STEP 3:
    // Outer loop controls the rows.
    //
    // For n = 8:
    // r takes values 0, 1, 2, 3, 4, 5, 6, 7.
    //
    // This generates exactly 8 rows.
    // for (int r = 0; r < n; r++) {

        // STEP 4:
        // Create an empty row filled with spaces.
        //
        // The width is 2*n - 1.
        //
        // For n = 8, the width is 15 characters.
        //
        // We will replace selected spaces with stars.
        // string line(2 * n - 1, ' ');

        // STEP 5:
        // Check the columns from 0 up to the current row.
        //
        // Row 0: check column 0.
        // Row 