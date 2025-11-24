#include <iostream>
#include <Vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target);

int main()
{
    vector<vector<int>> x = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    bool result = searchMatrix(x,6);

    if(result)
        cout<< "Target Exists";
    else
        cout<< "Target DOESN'T Exists";
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int top = 0, bottom = matrix.size()-1, left = 0, right = matrix[0].size()-1, mid = 0;

    // Specify the Target Row
    while(top <= bottom)
    {
        mid = (top + bottom)/2;
        if(matrix[mid][0] <= target && matrix[mid][right] >= target)
            break;
        else if(matrix[mid][0] > target)
            bottom--;
        else
            top++;
    }

    int targetRow = mid;

    // Specify the Target Element
    while(left <= right)
    {
        mid = (left + right)/2;
        if(matrix[targetRow][mid] == target)
            return true;
        else if(matrix[targetRow][mid] > target)
            right--;
        else
            left++;
    }

    // The target isn't exist
    return false;
}