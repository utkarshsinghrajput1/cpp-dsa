/*In C++, there are situations where a task needs to be repeated multiple times. For example, to print "Hello World" 5 times, we would have to write the cout statement 5 times if done manually.
Solution:
#include <iostream>
using namespace std;

int main() {
  
    cout << "Hello World\n";
    cout << "Hello World\n";
    cout << "Hello World\n";
    cout << "Hello World\n";
    cout << "Hello World";
    return 0;
}
 Writing it 20 times would take more effort, and writing it 100 times would be even more tedious, as the same statement must be repeated again and again.

In such cases, loops come into play, allowing users to repeatedly execute a block of statements any number of times.*/
#include <iostream>
using namespace std;

int main() {
  
  	for (int i = 0; i < 5; i++) {
    	cout << "Hello World\n";
    }
    return 0;
}