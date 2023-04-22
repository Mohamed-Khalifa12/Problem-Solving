#include<iostream>
#include<vector>

using namespace std;

int minInsertions(string s);
int solve(string& s, int i , int j, vector<vector<int>>& V);

int main()
{
    int result = minInsertions("tldjbqjdogipebqsohdypcxjqkrqltpgviqtqz");
    cout<< result;
}

int minInsertions(string s) {
    int n = s.size();
    vector<vector<int>> V (n, vector<int> (n));
    return n - solve(s, 0, n -1 , V);
}

int solve(string& s, int i , int j, vector<vector<int>>& V)
{
    if(V[i][j] != 0)
        return V[i][j]; 
    if(i == j)
        return 1;
    if(i > j)
        return 0;
    if(s[i] == s[j])
        V[i][j] = 2 + solve(s, i+1, j-1, V);
    else
        V[i][j] = max(solve(s,i, j-1, V), solve(s,i+1,j, V));
    
    return V[i][j];
}