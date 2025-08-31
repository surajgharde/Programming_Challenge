#include <bits/stdc++.h>
using namespace std;

vector<int> primeFactorization(long long n) {
    vector<int> factors;

    // Divide by 2 until odd
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Divide by odd numbers from 3 to sqrt(n)
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n is still greater than 2, then it's prime
    if (n > 2) {
        factors.push_back(n);
    }

    return factors;
}

int main() {
    long long N;
    cin >> N;

    vector<int> result = primeFactorization(N);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
