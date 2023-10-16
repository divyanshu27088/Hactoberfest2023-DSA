#include <iostream>
#include <vector>

int coinChangeWays(std::vector<int>& coins, int amount) {
    // Create a DP table to store the number of ways to make change for each amount.
    std::vector<int> dp(amount + 1, 0);
    dp[0] = 1;  // There is one way to make change for amount 0 (by not selecting any coin).

    // Loop through each coin denomination.
    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

int main() {
    std::vector<int> coins = {1, 2, 5};
    int amount = 5;
    int ways = coinChangeWays(coins, amount);

    std::cout << "Number of ways to make change for " << amount << " is: " << ways << std::endl;

    return 0;
}
