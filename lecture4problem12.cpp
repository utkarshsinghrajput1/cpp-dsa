// 13. Character Vowel or Consonant
// Character input lo aur check karo vowel hai ya consonant.
#include <iostream>
using namespace std;

int main() {
    char ch;

    cout << "Enter character: ";
    cin >> ch;

    if (ch == 'a' || ch == 'e' || ch == 'i' ||
        ch == 'o' || ch == 'u') {
        
        cout << "Vowel";
    }
    else {
        cout << "Consonant";
    }

    return 0;
}