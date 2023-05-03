#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2);

int main() {
    vector nums1 = {1,2,3}, nums2 = {2,4,6};
    vector<vector<int>> result = findDifference(nums1, nums2);

    for(auto raw: result)
    {
        for(int col : raw)
            cout<< col << "\t";
        cout<< "\n";
    }

}

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp1;
    unordered_map<int, int> mp2;
    vector<vector<int>> result(2);

    int i = 0, j = 0;
    int n1 = nums1.size(), n2 = nums2.size();

    while (i < n1 || j < n2)
    {
        if (i < n1)
            mp1[nums1[i++]] = 1;
        if (j < n2)
            mp2[nums2[j++]] = 1;
    }

    for (auto it = mp1.begin(); it != mp1.end(); ++it) {
        if(mp2.find(it->first) == mp2.end())
            result[0].push_back(it->first);
    }

    for(auto it = mp2.begin(); it != mp2.end(); ++it) {
        if(mp1.find(it->first) == mp1.end())
            result[1].push_back(it->first);
    }

    return result;
}