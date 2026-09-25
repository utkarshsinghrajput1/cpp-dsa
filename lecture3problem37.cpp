// 37. Social Media Follower Milestone
// Problem: Ek creator ke paas 8,500 followers hain aur wo 10,000 followers ka milestone achieve karna chahta hai. 
// Har hafte uske 300 followers badhte hain.
#include <iostream>
using namespace std;
int main() {
    int followers = 8500;
    int target = 10000;
    int weeks = 0;
    while (followers < target) {
        weeks++;
        followers += 300;
        cout << "Week " << weeks << " -> Followers: " << followers << endl;
    }
    cout << "Milestone Achieved in " << weeks << " weeks!" << endl;
    return 0;
}