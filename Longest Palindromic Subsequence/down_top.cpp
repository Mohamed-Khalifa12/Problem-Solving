#include <iostream>
#include<vector>

using namespace std;

int longestPalindromeSubseq(string s);

int main()
{
    string s = "bbbab";
    int result = longestPalindromeSubseq(s);
    cout<< result;    
}

int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> v (n,vector<int>(n));

    for(int i = n - 1; i >= 0; i--)
    {
        v[i][i] = 1;
        for(int j = i + 1; j < n; j++)
        {
            if(s[i] == s[j])
                v[i][j] = 2 + v[i+1][j-1];
            else
                v[i][j] = max(v[i][j-1], v[i+1][j]);
        }
    }

    return v[0][n-1];
}