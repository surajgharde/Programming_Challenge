#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;  
    
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }
    
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
     
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Test Case 1 Output: " << coinChange(coins1, amount1) << endl;
    
     
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Test Case 2 Output: " << coinChange(coins2, amount2) << endl;
    
     
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Test Case 3 Output: " << coinChange(coins3, amount3) << endl;
    
    return 0;
}
