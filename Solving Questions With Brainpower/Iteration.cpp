#include<iostream>
#include<vector>

using namespace std;

long long mostPoints(vector<vector<int>>& questions);

int main() {
    vector<vector<int>> questions = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    long long result = mostPoints(questions);
    cout<< result;
}

long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();
    vector<long long> dp(questions.size());
    dp[n - 1] = questions[n-1][0];

    for(int i = n - 2; i >= 0; i--)
    {
        dp[i] = questions[i][0];
        int skipped = i + 1 + questions[i][1];
        if(skipped < n)
            dp[i] += dp[skipped];
        dp[i] = max(dp[i], dp[i+1]);
    }
    return dp[0];
}