#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void splitString(string str, vector<string>& V);
string simplifyPath(string path);

int main()
{
    string str = "/home//foo/";
    string result = simplifyPath(str);
    cout<< result;
}

string simplifyPath(string path) {
    vector<string> V;
    splitString(path, V);
    stack<string> st;
    string result = "";

    for(string str : V)
    {
        if(str == "..")
        {
            if(!st.empty())
                st.pop();
        }
        else if(str != ".")
            st.push(str);
    }

    if(st.empty())
        return "/";

    while (!st.empty())
    {
        result = '/' + st.top() + result;
        st.pop();
    }
    
    return result;
}

void splitString(string str, vector<string>& V)
{
    string subString = "";
    int i = 0;

    while (str[i] != '\0')
    {
       if(str[i] == '/')
       {
            if(subString.size() > 0)
            {
                V.push_back(subString);
                subString = "";
            }
       }
       else
       {
        subString.push_back(str[i]);
       }
       i++;
    }

    if(subString != "")
    {
        V.push_back(subString);
    }
}