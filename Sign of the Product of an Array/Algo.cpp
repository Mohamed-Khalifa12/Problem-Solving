#include <iostream>
#include <vector>

using namespace std;

int arraySign(vector<int>& nums);

int main() {
    vector<int> nums = {-1,1,-1,1,-1};
    int result = arraySign(nums);
    cout<< result;
}

int arraySign(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(nums[i] == 0)
            return 0;
        if(nums[i] < 0)
            count++;
    }

    if(count % 2 == 0)
        return 1;
    return -1;
}