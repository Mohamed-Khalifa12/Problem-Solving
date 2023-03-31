#include <iostream>
#include <vector>

using namespace std;

long long MOD = 1000000007;

bool isValid(vector<string>& pizza, int startRow, int endRow, int startCol, int endCol);
int solve(vector<string>& pizza, vector<vector<vector<int>>>&dp, int startRow, int startCol, int cutsLeft);
int ways(vector<string>& pizza, int k);

int main()
{
    vector<string> pizza = {"A..","AAA","..."};
    int result = ways(pizza, 3);
    cout << result;
}

bool isValid(vector<string>& pizza, int startRow, int endRow, int startCol, int endCol)
{
    for(int i = startRow; i <= endRow; i++)
    {
        for(int j = startCol; j <= endCol; j++)
        {
            if(pizza[i][j] == 'A')
                return true;
        }
    }
    return false;
}

int solve(vector<string>& pizza, vector<vector<vector<int>>>&dp, int startRow, int startCol, int cutsLeft)
{
    int m = pizza.size(); int n = pizza[0].size();

    if(cutsLeft == 0) return 1;

    if (dp[startRow][startCol][cutsLeft] != -1) return dp[startRow][startCol][cutsLeft];

    long long ans = 0;

    //looping throw the rows to calc the number of cuts
    for(int row = startRow; row < m - 1; row++)
    {
        bool upperValid = isValid(pizza, startRow, row, startCol, n - 1);
        bool lowerValid = isValid(pizza, row + 1, m - 1, startCol, n - 1);

        if(upperValid && lowerValid)
        {
            int value = solve(pizza, dp, row + 1, startCol, cutsLeft - 1);
            ans = (ans + value) % MOD;
        }
    }

    // looping throw the colums and cal the number of cuts
    for(int col = startCol; col < n - 1; col++)
    {
        bool leftValid = isValid(pizza, startRow, m - 1, startCol, col);
        bool rightValid = isValid(pizza, startRow, m - 1, col + 1, n - 1 );
        if(leftValid && rightValid)
        {
            int value = solve(pizza, dp, startRow, col + 1 , cutsLeft -1);
            ans = (ans + value) % MOD;
        }
    }

    return dp[startRow][startCol][cutsLeft] = (int)ans;
}

int ways(vector<string>& pizza, int k) {
    int m = pizza.size(), n = pizza[0].size();
    vector dp(m, vector(n, vector<int>(k, -1)));
    int answer = solve(pizza, dp, 0, 0, k-1);
    return answer;
}