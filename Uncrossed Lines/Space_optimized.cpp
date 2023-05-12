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
    int m = nums1.size(), n = nums2.size();
    if (m < n) {
        swap(nums1, nums2);
        swap(m, n);
    }
    vector<int> dp(n + 1);
    for (int i = 1; i <= m; i++) {
        int prev = 0;
        for (int j = 1; j <= n; j++) {
            int curr = dp[j];
            if (nums1[i-1] == nums2[j-1]) {
                dp[j] = prev + 1;
            } else {
                dp[j] = max(dp[j-1], curr);
            }
            prev = curr;
        }
    }
    return dp[n];
}