#include "KthLargest.h"

KthLargest::KthLargest(int k, vector<int>& nums)
{
    this->k = k;

    for(int i = 0; i < nums.size(); i++)
        this->pq.push(nums[i]);
}

int KthLargest::add(int val) {
    this->pq.push(val);
    while (this->pq.size() > this->k)
    {
        this->pq.pop();
    }
    
    return pq.top();
}