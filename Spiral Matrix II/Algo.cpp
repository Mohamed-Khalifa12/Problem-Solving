#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generateMatrix(int n);

int main() {
    vector<vector<int>> result;
    result = generateMatrix(3);

    for(auto row: result)
    {
        for (auto col : row)
            cout << col << "   ";    
    }
}

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n));
    int left = 0, right = n - 1;
    int top = 0, bottom = n - 1;
    int value = 1;

    while (value <= n*n)
    {
        for(int i = left; i <= right; i++)
            result[top][i] = value++;
        top++;
        for(int i = top; i <= bottom; i++)
            result[i][right] = value++;
        right--;
        for(int i = right; i >= left; i--)
            result[bottom][i] = value++;
        bottom--;
        for(int i = bottom; i >= top; i--)
            result[i][left] = value++;
        left++;
    }

    return result;
}