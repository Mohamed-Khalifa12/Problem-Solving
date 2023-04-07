#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};
int numEnclaves(vector<vector<int>>& grid);
void dfs(vector<vector<int>>& grid, int i, int j);

int main()
{
    vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    int result = numEnclaves(grid);
    cout<< result;
}

int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int sum = 0;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((i == 0 || j == 0 || i == m - 1 || j == n - 1) && grid[i][j])
            {
                dfs(grid, i , j);
            }
        }
    }

    for(vector<int>& row : grid)
    {
        for(int &col : row)
            sum += col;
    }
    return sum;
}

void dfs(vector<vector<int>>& grid, int i, int j)
{
    grid[i][j] = 0;
    for(vector<int> & direction : directions)
    {
        int x = i + direction[0];
        int y = j + direction[1];
        if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y])
            dfs(grid, x, y);
    }
}