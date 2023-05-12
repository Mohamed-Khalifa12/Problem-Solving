#include<iostream>
#include<vector>

using namespace std;

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2);

int main() {
    vector<int> nums1 = {2,5,1,2,5};
    vector<int> nums2 = {10,5,2,1,5,2};
    int result = maxUncrossedLines(nums1, nums2);
    cout<< result;
}

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for(int i = 1; i <= n1; i++)
    {
        for(int j = 1; j <= n2; j++)
        {
            if(nums1[i - 1] == nums2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n1][n2];
}