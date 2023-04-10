#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s);

int main()
{
    string par = "((";
    bool result = isValid(par);
    cout<< result;
}

bool isValid(string s) {
    int n = s.size();
    if(n % 2 == 1)
        return false;
    
    stack<char> st;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            if(st.empty())
                return false;
            int last = st.top();
            st.pop();
            if(last == '(')
            {
                if(s[i] - 1 != last)
                    return false;
            }
            else
            {
                if(s[i] - 2 != last)
                    return false;                
            }
        }
    }

    if(st.empty())
        return true;
    else
        return false;
}