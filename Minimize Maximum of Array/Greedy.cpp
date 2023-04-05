#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int minimizeArrayValue(vector<int>& nums);

int main()
{
    vector<int> nums = {13,13,20,0,8,9,9};
    int result = minimizeArrayValue(nums);
    cout<< result;
}

int minimizeArrayValue(vector<int>& nums) {
    int prefixsum = 0;
    int output = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        prefixsum += nums[i];
        output = max(output, (int) ceil((double)prefixsum/(i + 1)));
    }
    return output;
}