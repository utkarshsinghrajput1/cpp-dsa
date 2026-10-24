// Problem 12: Hospital Medicine Distribution
// Real-world question: Hospital ke paas 100 medicine units hain. Emergency, general aur pediatric wards ki demands respectively 40, 35 aur 45 units hain. Emergency ward ko pehle medicine deni hai. Har ward ko uski poori demand mile tabhi request accept karo; warna request reject karo.

#include <iostream>
using namespace std;

int main() {
    int stock = 100;

    int emergencyDemand = 40;
    int generalDemand = 35;
    int pediatricDemand = 45;

    int emergencyGiven = 0;
    int generalGiven = 0;
    int pediatricGiven = 0;

    int rejected = 0;

    // Emergency ward gets first priority
    if (stock >= emergencyDemand) {
        emergencyGiven = emergencyDemand;
        stock = stock - emergencyGiven;
    } else {
        rejected++;
    }

    // General ward is considered after emergency
    if (stock >= generalDemand) {
        generalGiven = generalDemand;
        stock = stock - generalGiven;
    } else {
        rejected++;
    }

    // Pediatric ward receives whatever remains if sufficient
    if (stock >= pediatricDemand) {
        pediatricGiven = pediatricDemand;
        stock = stock - pediatricGiven;
    } else {
        rejected++;
    }

    cout << "Emergency medicine: " << emergencyGiven << "\n";
    cout << "General medicine: " << generalGiven << "\n";
    cout << "Pediatric medicine: " << pediatricGiven << "\n";

    cout << "Remaining stock: " << stock << "\n";
    cout << "Rejected requests: " << rejected << "\n";

    return 0;
}
// Important logic:
// - stock ek shared resource hai; har successful allocation ke baad decrease hota hai.
// - Ward order hi priority order hai.
// - Request tabhi accepted hai jab remaining stock poori demand fulfill kar sake.
// - Example mein emergency ko 40, general ko 35 milenge; pediatric ki 45-unit request reject hogi, kyunki sirf 25 units bachengi.
