#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int threeSumClosest(vector<int>& nums, int target);

int main()
{
    vector <int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);

    int sum = threeSumClosest(v, 1);
    cout << sum;
}

int threeSumClosest(vector<int>& nums, int target) {
    int diff = INT_MAX, sum = 0;
    sort(nums.begin(), nums.end());
    int length = nums.size();
    for(int i = 0; i < length -2 ; i++)
    {
        int start = nums[i];
        int low = i+1, high = length-1;
        while (low < high)
        {
            if((start + nums[low] + nums[high]) == target)
                return target;
            if(abs(start + nums[low] + nums[high] - target) < diff)
            {
                diff = abs(start + nums[low] + nums[high] - target);
                sum = start + nums[low] + nums[high];
            }
            if(start + nums[low] + nums[high] < target)
                low++;
            else
                high--;
        }  
    }
    return sum;
}