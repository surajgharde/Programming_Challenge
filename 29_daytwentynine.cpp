 #include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

 
using BigInt = cpp_int;

BigInt fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    vector<BigInt> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << fibonacci(n) << endl;

    return 0;
}
