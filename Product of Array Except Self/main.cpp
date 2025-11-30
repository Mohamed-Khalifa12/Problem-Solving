#include <iostream>
#include <Vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums);


int main()
{
    vector<int> x = {1,2,3,4};

    vector<int> result = productExceptSelf(x);

    for(int i = 0; i < result.size(); i++)
    {
        cout<< result[i] << "\t";
    }
}

vector<int> productExceptSelf(vector<int>& nums) {
    int l = nums.size();
    vector<int> output(l,1);

    int left = 1, right = 1;

    for(int i = 0; i < l; i++)
    {
        output[i] *= left;
        left *= nums[i];
    }

    for(int i = l - 1; i >= 0; i--)
    {
        output[i] *= right;
        right *= nums[i];
    }

    return output;
}