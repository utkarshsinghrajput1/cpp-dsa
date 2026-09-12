// This program calculates the area of a rectangle using the multiplication operator.
#include <iostream>
using namespace std;

int main() {
    double length, width, area;

    // Taking input from the user
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    // Using the multiplication operator
    area = length * width;

    // Displaying the result
    cout << "The area of the rectangle is: " << area << endl;

    return 0;
}
