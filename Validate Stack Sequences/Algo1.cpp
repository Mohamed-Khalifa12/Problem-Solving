#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped);

int main()
{
    vector<int> pushed = {1,2,3,4,5};
    vector<int> poped = {4,3,5,1,2};
    bool seq = validateStackSequences(pushed, poped);
    cout<< seq;
}

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int i = 0;
    int j = 0;
    stack<int> st;
    st.push(pushed[i++]);

    while (j < popped.size())
    {
        if(!st.empty() && popped[j] == st.top())
        {
            st.pop();
            j++;
        }
        else if(i < pushed.size())
            st.push(pushed[i++]);
        else
            return false;
    }
    return true;
}

