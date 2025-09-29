#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string common = "";
    int arr_length = strs.size();
    sort(strs.begin(), strs.end());

    string first = strs[0], last = strs[arr_length - 1];

    for(int i = 0; i < min(first.size(), last.size()); i++)
    {
        if(first[i] != last[i])
            break;
        common += strs[0][i];
    }

    return common;
}

int main()
{
    vector<string> str = {"flower","flow","flight"};

    string result = longestCommonPrefix(str);

    cout<< result;
}