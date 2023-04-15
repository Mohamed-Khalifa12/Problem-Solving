#include<iostream>
#include<vector>

using namespace std;

int maxValueOfCoins(vector<vector<int>>& piles, int k);

int main()
{
    vector<vector<int>> piles = {{37,88},{51,64,65,20,95,30,26},{9,62,20},{44}};
    int result = maxValueOfCoins(piles, 7);
    cout<< result;
}

int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    int n = piles.size();
    vector<vector<int>> dp(n+1, vector<int>(k+1));

    for(int i = 1; i <= n; i++)
    {
        for(int coins = 0; coins <= k; coins++)
        {
            int currentSum = 0;
            for(int currentCoins = 0; currentCoins <= min(coins, (int)piles[i-1].size()); currentCoins++)
            {
                if(currentCoins > 0)
                {
                    currentSum += piles[i-1][currentCoins-1];
                }
                dp[i][coins] = max(dp[i][coins], dp[i-1][coins-currentCoins] + currentSum);
            }
        }
    }

    return dp[n][k];
}
