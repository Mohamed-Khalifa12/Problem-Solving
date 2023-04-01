#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target);
int BS(vector<int>& nums, int start, int end, int target);

int main()
{
    vector<int> nums = {2, 5};
    int index = search(nums, 0);
    cout << index;
}

int search(vector<int>& nums, int target) {
    int length = nums.size();
    return BS(nums, 0, length , target);
}

int BS(vector<int>& nums, int start, int end, int target){
    if(start > end)
        return -1;

    int mid = (start + end) / 2;

    if(nums[mid] == target)
        return mid;
    if(nums[mid] > target)
        return BS(nums, start, mid - 1, target);
    return BS(nums, mid + 1, end, target);
}