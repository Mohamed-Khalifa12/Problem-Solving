#include <iostream>
#include <Vector>

using namespace std;


int minimumOperations(vector<int>& nums);

int main() {

    vector<int> x = {1,2,3,4};

    int res = minimumOperations(x);

    cout<< res;

    return 0;
}

int minimumOperations(vector<int>& nums) {
   int len = nums.size(), count = 0;

   for(int i = 0; i < len; i++)
   {
        if(nums[i] % 3 == 0)
            count++;
   }

   return len - count;
}