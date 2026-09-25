// 38. File Download Simulator
// Problem: Ek 100 MB ki file download ho rahi hai. 
// Har second me 18 MB download hota hai. 
// Jab tak 100 MB complete na ho, progress dikhao.
#include <iostream>
using namespace std;
int main() {
    int downloaded = 0;
    int total_size = 100;
    int speed = 18;
    int sec = 0;
    while (downloaded < total_size) {
        sec++;
        downloaded += speed;
        if(downloaded > total_size) downloaded = total_size;
        cout << "Second " << sec << " -> Downloaded: " << downloaded << "%" << endl;
    }
    cout << "Download Complete!" << endl;
    return 0;
}