#include<iostream>
#include<vector>

using namespace std;

int numberOfArrays(string s, int k);
int dfs(const string& s, long k, int i, vector<int>& memo);

int main(){
    int result = numberOfArrays("1000", 10);
    cout<< result;
}

int dfs(const string& s, long k, int i, vector<int>& memo) {
    if (i == s.size()) return 1;
    if (s[i] == '0') return 0;
    if (memo[i] != -1) return memo[i];

    int ans = 0;
    long num = 0;
    for (int j = i; j < s.size(); j++) {
        num = num * 10 + s[j] - '0';
        if (num > k) break;
        ans = (ans + dfs(s, k, j + 1, memo))%1000000007;
    }
    return memo[i] = ans;
}

int numberOfArrays(string s, int k) {
    vector<int> memo(s.size(), -1);
    return dfs(s, k, 0, memo);
}