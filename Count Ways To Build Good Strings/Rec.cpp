#include<iostream>
#include<vector>

using namespace std;

int mod = 1000000007;

int countGoodStrings(int low, int high, int zero, int one);
int solve(int i, int zero, int one, vector<int>& memo);

int main() {
    int result = countGoodStrings(2,3,2,1);
    cout<< result;
}

int countGoodStrings(int low, int high, int zero, int one) {
    vector<int> memo (high + 1, -1);
    memo[0] = 1;

    int answer = 0;
    for(int i = low; i <= high; i++)
    {
        answer += solve(i, zero, one, memo);
        answer %= mod;
    }
    return answer;
}

int solve(int i, int zero, int one, vector<int>& memo) {
    if(memo[i] != -1)
        return memo[i];
    int count = 0;
    if(i >= one)
        count += solve(i - one, zero, one, memo);
    if(i >= zero)
        count += solve(i - zero, zero, one, memo);
    memo[i] = count % mod;
    return memo[i];
}