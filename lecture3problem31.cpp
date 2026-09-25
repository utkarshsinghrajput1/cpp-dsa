// 12. Book Reading Challenge
// Problem: Ek 300 pages ki book hai. 
// Tum roz 45 pages padhte ho. Kitne dino me book khatam hogi?
#include <iostream>
using namespace std;
int main() {
    int total_pages = 300;
    int read_pages = 0;
    int days = 0;
    while (read_pages < total_pages) {
        days++;
        read_pages += 45;
        if(read_pages > total_pages) read_pages = total_pages;
        cout << "Day " << days << " -> Pages read: " << read_pages << "/" << total_pages << endl;
    }
    return 0;
}