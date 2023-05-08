#include<iostream>
#include<vector>

using namespace std;

int diagonalSum(vector<vector<int>>& mat);

int main() {
      vector<vector<int>> mat = {{1,1,1,1},{1,1,1,1}, {1,1,1,1}, {1,1,1,1}};
      int result = diagonalSum(mat);
      cout<< result;
}

int diagonalSum(vector<vector<int>>& mat) {
      int n = mat.size();
      int summer = 0;

      for(int i = 0; i < n; i++)
      {
            for(int j = 0; j < n; j++)
            {
                  if(i == j)
                        summer += mat[i][j];
                  else if(i + j == n -1)
                        summer += mat[i][j];
            }
      }
      return summer;
}