#include<iostream>
#include<vector>
#include <queue>

using namespace std;

class KthLargest
{
private:
   priority_queue<int,vector<int>,greater<int>> pq;
   int k;
public:
    KthLargest(int k, vector<int>& nums);
    int add(int val);
};
