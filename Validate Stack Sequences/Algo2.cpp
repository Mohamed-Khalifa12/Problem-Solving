#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped);

int main()
{
    vector<int> pushed = {1,2,3,4,5};
    vector<int> poped = {4,5,3,2,1};
    bool seq = validateStackSequences(pushed, poped);
    cout<< seq;
}

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int j = 0;
    for(int x : pushed)
    {
        st.push(x);
        while (!st.empty() && popped[j] == st.top())
        {
           st.pop();
           j++;
        }
    }
    if(st.empty())
        return true;
    return false;
}