#include<iostream>
#include<stack>

using namespace std;

string removeStars(string s);

int main()
{
    string s = "leet**cod*e";
    string newString = removeStars(s);
    cout<< newString;
}

// Non effecient as erase function O(n) so we can depend on stack data structrue

// string removeStars(string s) {
//     int i = 0;
//     while (s[i] != '\0')
//     {
//         if(s[i] == '*')
//         {
//             s.erase(i- 1, 2);
//             i--;
//             continue;
//         }
//         i++;
//     }
//     return s;
// }

string removeStars(string s){
    int i = 0;
    stack<char> st;
    string output = "";

    while(s[i] != '\0')
    {
        if(s[i] == '*')
            st.pop();
        else
            st.push(s[i]);
        i++;
    }

    while (!st.empty())
    {
        output.push_back(st.top());
        st.pop();
    }

    reverse(output.begin(), output.end());
    return output;
}