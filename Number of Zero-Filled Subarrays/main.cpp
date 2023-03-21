#include <iostream>
#include <vector>
using namespace std;

long long zeroFilledSubarray(vector<int>& nums);

int main()
{
    vector v = {0,0,0,2,0,0};
    long long result = zeroFilledSubarray(v);
    cout<< result;
}

long long zeroFilledSubarray(vector<int>& nums) {
    long cnt = 0, zeroSubarraysEndingAtCurrentIndex = 0;
    for (int n : nums) {
        if (n == 0) {
            cnt += ++zeroSubarraysEndingAtCurrentIndex;
        } else {
            zeroSubarraysEndingAtCurrentIndex = 0;
        }
    }
    return cnt;
}
