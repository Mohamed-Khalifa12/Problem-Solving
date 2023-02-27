#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& num1, vector<int>& num2);
double auto_fun(vector<int>& num1, vector<int>& num2, int left, int right, int side, int Length, bool is_even);
bool isEven(int length);

int main()
{
    vector<int> num1, num2;
    num1.push_back(1);
    num1.push_back(2);
    num2.push_back(3);
    num2.push_back(4);


    double result = findMedianSortedArrays(num1, num2);
    cout<<"Result = " << result;
}

double findMedianSortedArrays(vector<int>& num1, vector<int>& num2)
{
    int L1 = size(num1), L2 = size(num2), Length = L1 + L2;
    int side = Length/2;
    int left = 0, right = L1;
    bool is_even = isEven(Length);
    if(L1 == 0)
        return is_even ? ((double)num2[side -1] + num2[side])/2: num2[side];
    if(L2 == 0)
        return is_even ? ((double)num1[side -1] + num1[side])/2: num1[side];
    return auto_fun(num1, num2, left,right, side, Length, is_even);
}

double auto_fun(vector<int>& num1, vector<int>& num2, int left, int right, int side, int Length, bool is_even)
{
    int m = (left + right)/2;
    int n = side - m;
    int prev1 = num1[m-1] ? num1[m-1] : INT_MIN;
    int prev2 = num2[n-1] ? num2[n-1] : INT_MIN;
    int inst1 = num1[m] ? num1[m] : INT_MAX;
    int inst2 = num2[n] ? num2[n] : INT_MAX;

    if(inst1 < prev2)
        return auto_fun(num1, num2, m + 1,right, side, Length, is_even);
    if(inst2 < prev1)
        return auto_fun(num1, num2, m + 1,right , side, Length, is_even); // we need t ochange something
    return is_even? ((double)max(prev1, prev2) + min(inst1, inst2))/2: min(inst1, inst2);

}

bool isEven(int length)
{
    return length%2 == 0? true: false;
}