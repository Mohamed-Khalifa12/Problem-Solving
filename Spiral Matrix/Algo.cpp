#include<iostream>
#include<vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix);

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> output = spiralOrder(matrix);
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << " ";
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    if (n == 0 || m == 0) {
        return vector<int>();
    }
    vector<int> output;
    int bottom  = n - 1, right = m - 1;
    int left = 0, top = 0;

    while (output.size() < n*m)
    {
        for(int i = left; i <= right; i++)
            output.push_back(matrix[top][i]);
        top++;

        for(int i = top; i <= bottom; i++)
            output.push_back(matrix[i][right]);
        right--;

        if(top <= bottom) {
            for(int i = right; i >= left; i--)
                output.push_back(matrix[bottom][i]);
            bottom--;
        }

        if(left <= right) {
            for(int i = bottom; i >= top; i--)
                output.push_back(matrix[i][left]);
            left++;  
        }
    }
    
    return output;
}