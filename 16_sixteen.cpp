#include <bits/stdc++.h>
using namespace std;

// Function to calculate LCM using GCD
long long lcm(long long a, long long b) {
    long long g = __gcd(a, b);         // Built-in GCD function
    return (a / g) * b;                // Divide first to avoid overflow
}

int main() {
    long long N, M;
    cin >> N >> M;
    cout << lcm(N, M) << endl;
    return 0;
}
