#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int longestPalindromeSubseq(string s);
int help(string& s, int i , int j, vector<vector<int>>& V);

int main()
{
    string s = "bbbab";
    int result = longestPalindromeSubseq(s);
    cout<< result;
}

int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> V (n, vector<int> (n));
    return help(s, 0, n -1 , V);
}

int help(string& s, int i , int j, vector<vector<int>>& V)
{
    if(V[i][j] != 0)
        return V[i][j]; 
    if(i == j)
        return 1;
    if(i > j)
        return 0;
    if(s[i] == s[j])
        V[i][j] = 2 + help(s, i+1, j-1, V);
    else
        V[i][j] = max(help(s,i, j-1, V), help(s,i+1,j, V));
    
    return V[i][j];
}