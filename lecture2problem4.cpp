/*Problem Statement:
Given an integer N and a 0-indexed position K, write a C++ function to check if the K-th bit of N is set to 1 or not. Your function should return true if the bit is 1, and false if it is 0. */
// Solution:
#include <iostream>

// Function to check if K-th bit is set
bool isKthBitSet(int n, int k) {
    // 1. (1 << k) creates a mask with only the K-th bit set to 1
    // 2. n & mask isolates the K-th bit of n
    // 3. If the result is not 0, the bit was 1 (set)
    return (n & (1 << k)) != 0;
}

int main() {
    int N = 5; // Binary: 00000101
    int K = 2;

    if (isKthBitSet(N, K)) {
        std::cout << "The " << K << "-th bit of " << N << " is SET (1).\n";
    } else {
        std::cout << "The " << K << "-th bit of " << N << " is NOT SET (0).\n";
    }

    return 0;
}
