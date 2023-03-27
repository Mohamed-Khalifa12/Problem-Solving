#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid);

int main()
{
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    int minPath = minPathSum(grid);
    cout<< minPath;
}

int minPathSum(vector<vector<int>>& grid) {
    int rowsNum = grid.size();
    int colNum = grid[0].size();

    //summing all Number of the first row
    for(int i = 1; i < colNum; i++) 
    {
        grid[0][i] += grid[0][i-1];
    }

    //summing all numbers of first colu
    for(int i = 1; i < rowsNum; i++)
    {
        grid[i][0] += grid[i-1][0];
    }

    for(int i = 1; i < rowsNum; i++)
    {
        for(int j = 1; j < colNum; j++)
        {
            grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
    }
    return grid[rowsNum-1][colNum-1];
}