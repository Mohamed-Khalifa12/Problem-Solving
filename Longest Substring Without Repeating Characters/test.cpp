#include <iostream>
#include <map>
using namespace std;


int lengthOfLongestSubstring(string s);

int main()
{
    string str = "pwwkew";
    int len = lengthOfLongestSubstring(str);

    cout << "output: " << len;
 
}

int lengthOfLongestSubstring(string s) {
    int length= 0, maxLength = 0, left = 0;
    map <char, int> mp;

    for (int right = 0; right < size(s); right++)
    {
        length++;
        mp[s[right]]++;
        while(mp[s[right]] > 1)
        {
            length--;
            mp[s[left++]]--;
        }
        maxLength = max(maxLength, length);
    }
    
    return maxLength;
}