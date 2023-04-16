#include<iostream>
#include<vector>

using namespace std;

const int mod = 1000000007;

int numWays(vector<string>& words, string target);

int main()
{
    vector<string> words = {"dcdccdabba","ddabcadabc","dbcdbaccba","cddadbdccd","adacdbaadb","cababaccbc","ccbccbaabd","bcdacdadcb","daddbbcaba","abbcaddbab","bbcdabadab","cabababccb","cadddddcba","accaabadbd","baabcabdbc","acbacdbbbc"};
    int ways = numWays(words, "dcdaad");
    cout<< ways;
}

int numWays(vector<string>& words, string target) {
    int m = target.size();
    int k = words[0].size();
    vector<vector<int>> cnt(26,vector<int>(k));

    for(int j = 0; j < k; j++)
    {
        for(string& word: words)
        {
            cnt[word[j] - 'a'][j]++;
        }
    }

    vector<vector<int>> dp(m + 1, vector<int>(k + 1));
    dp[0][0] = 1;

    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j < k; j++)
        {
            if(i < m)
                dp[i+1][j+1] += (dp[i][j] * cnt[target[i] - 'a'][j])%mod;
            dp[i][j+1] += dp[i][j]%mod;
        }
    }
    return dp[m][k];
}

// const int MOD = 1000000007;
// int numWays(vector<string>& words, string target) {
//     int l = target.size(), m = words[0].size(), n = words.size();
//     return lbs(words, target, 0, 0, n, m, l);
// }

// int lbs(vector<string>& words, string& target, int j, int i, int n, int m, int l){
//     int res;
//     if(i == l)
//         return 1;
//     if(j == m)
//         return 0;
    
//     int getMeToTheEnd = lbs(words, target, j + 1, i, n, m, l)%MOD;

//     int currentways = 0, collectedData = 0;
//     for(int count = 0; count < n; count++)
//     {
//         if(words[count][j] == target[i])
//             currentways++;
//     }

//     collectedData = (currentways%MOD* (long long)lbs(words, target, j + 1, i + 1, n, m, l)%MOD)%MOD;

//     return (collectedData + getMeToTheEnd);
// }
