// Student Marks Analyzer
// Question: Students ke marks repeatedly input karo. -1 par input stop ho. Highest, lowest aur average calculate karo.
// Solution:
#include <iostream>
using namespace std;

int main()
{
    int marks;                            // [INPUT]
    int count = 0;                        // [COUNTER]
    int total = 0;                        // [ACCUMULATOR]
    int highest = 0;                      // [TRACKER]
    int lowest = 100;                     // [TRACKER]

    cout << "Enter marks (-1 to stop): ";
    cin >> marks;

    while (marks != -1)                   // [LOOP] -1 tak input
    {
        total = total + marks;            // [UPDATE] Total marks
        count++;                          // [UPDATE] Student count

        if (marks > highest)              // [CHECK] Highest?
        {
            highest = marks;
        }

        if (marks < lowest)               // [CHECK] Lowest?
        {
            lowest = marks;
        }

        cout << "Enter marks (-1 to stop): ";
        cin >> marks;                     // [NEXT INPUT]
    }

    cout << "\nTotal = " << total;
    cout << "\nStudents = " << count;
    cout << "\nHighest = " << highest;
    cout << "\nLowest = " << lowest;

    if (count > 0)
    {
        cout << "\nAverage = " << (double)total / count;
    }

    return 0;
}