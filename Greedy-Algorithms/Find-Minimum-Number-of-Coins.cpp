#include <bits/stdc++.h> 
using namespace std;

int findMinimumCoins(int amount) 
{
    vector<int> coins = {1000, 500, 100, 50, 20, 10, 5, 2, 1};

    // We will start from the highest denomination
    int coinIndex = 0, res = 0;
    while(amount > 0) {
        // If the current coin is greater than the remaining amount, 
        // we will move to the next lower denomination coin
        if(amount < coins[coinIndex]) {
            coinIndex++;
        }

        // We will add the number of coins of the current denomination
        res += (amount / coins[coinIndex]);
        // We will reduce the remaining amount
        amount %= coins[coinIndex];
    }

    // Return the minimum number of coins required
    return res;
}
