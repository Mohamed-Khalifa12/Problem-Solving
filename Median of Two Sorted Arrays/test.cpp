#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& num1, vector<int>& num2);
double auto_fun(vector<int>& num1, vector<int>& num2, int start, int end);
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
    int L1 = size(num1), L2 = size(num2);
    if(L2 < L1)
        return findMedianSortedArrays(num2, num1);
    return auto_fun(num1, num2, 0, L1);
}

double auto_fun(vector<int>& num1, vector<int>& num2, int start, int end)
{
    int L1 = num1.size(), L2 = num2.size();
    int m = (start + end)/2;
    int n = (L1 + L2 + 1)/2 - m;

    int prev1 = m == 0 ? INT_MIN : num1[m - 1];
    int prev2 = n == 0 ? INT_MIN : num2[n - 1];
    int inst1 = m == L1 ? INT_MAX : num1[m];
    int inst2 = n == L2 ? INT_MAX : num2[n];

    if(inst1 < prev2)
        return auto_fun(num1, num2, m + 1, end);
    if(inst2 < prev1)
        return auto_fun(num1, num2, start, m - 1);
    return isEven(L1+L2) ? ((double)min(inst1, inst2) + max(prev1, prev2))/2 : max(prev1, prev2);
}

bool isEven(int length)
{
    return length%2 == 0? true: false;
}