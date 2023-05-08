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
      if(mat.size() == 1)
            return mat[0][0];
      int min = 0, max = mat.size() - 1;
      while (min + 1 < max - 1)
      {
            mat[min + 1][min + 1] += mat[min][min];
            mat[min + 1][max - 1] += mat[min][max];
            mat[max - 1][min + 1] += mat[max][min];
            mat[max - 1][max - 1] += mat[max][max];
            min++; max--;
      }

      int summer = mat[min][min] + mat[min][max] + mat[max][min] + mat[max][max];

      if(!(mat.size() % 2))
            return summer;
      return summer + mat[min + 1][min + 1];

}