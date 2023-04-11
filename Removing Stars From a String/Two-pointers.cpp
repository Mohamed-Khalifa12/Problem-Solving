#include <iostream>

using namespace std;

string removeStars(string s);

int main()
{
    string s = "leet**cod*e";
    string newString = removeStars(s);
    cout<< newString;
}

string removeStars(string s) {
    ios_base::sync_with_stdio(false);
    int j = 0;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '*') j--;
        else s[j++] = s[i];
    }

    return s.substr(0,j);
}