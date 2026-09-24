// 27. Game Level Progression (XP Collector)
// Problem: Ek RPG game me player ko Level up karne ke liye 500 XP chahiye. 
// Player har quest se 120 XP earn karta hai. 
// Jab tak 500 XP na ho jaye, quests simulate karo.
#include <iostream>
using namespace std;
int main() {
    int xp = 0;
    int target_xp = 500;
    int quests = 0;
    while (xp < target_xp) {
        quests++;
        xp += 120;
        cout << "Quest " << quests << " completed! Total XP: " << xp << endl;
    }
    cout << "Level Up achieved in " << quests << " quests!" << endl;
    return 0;
}