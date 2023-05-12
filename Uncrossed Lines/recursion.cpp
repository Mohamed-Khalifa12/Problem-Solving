#include<iostream>
#include<vector>

using namespace std;

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2);
int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& memo);

int main() {
    vector<int> nums1 = {2,5,1,2,5};
    vector<int> nums2 = {10,5,2,1,5,2};
    int result = maxUncrossedLines(nums1, nums2);
    cout<< result;
}

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
    return solve(n1, n2, nums1, nums2, dp);
}

int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& memo) {
    if(i <= 0 || j <= 0)
        return 0;
    if(memo[i][j] != -1)
        return memo[i][j];
    if(nums1[i - 1] == nums2[j - 1])
        memo[i][j] = 1 + solve(i-1, j -1, nums1, nums2, memo);
    memo[i][j] = max(solve(i-1, j, nums1, nums2, memo), solve(i, j -1, nums1, nums2, memo));
    return memo[i][j];
}   