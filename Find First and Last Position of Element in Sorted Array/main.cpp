#include <iostream>
#include <Vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target);
int searchValue(vector<int>& nums, int target, bool isLeft);

int main()
{
    vector<int> x = {5,7,7,8,8,10};
    vector<int> result = searchRange(x, 8);

    for(int i = 0; i < 2; i++)
    {
        cout<< result[0] << "\t" << result[1];
    }
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result = {-1, -1};
    int left = searchValue(nums, target, true);
    int right = searchValue(nums, target, false);
    result[0] = left;
    result[1] = right;

    return result;
}

int searchValue(vector<int>& nums, int target, bool isLeft)
{
    int left = 0, right = nums.size() - 1, idx = -1;
    while(left <= right)
    {
        int mid = (left + right)/2;
        if(nums[mid] > target)
            right = mid - 1;
        else if(nums[mid] < target)
            left = mid + 1;
        else
        {
            idx = mid;
            if(isLeft)
                right = mid - 1;
            else
                left = mid + 1;
        }
    }

    return idx;
}