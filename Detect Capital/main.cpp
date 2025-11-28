#include <iostream>
#include <string>

using namespace std;

bool detectCapitalUse(string word);

int main()
{
    string s = "USA";
    cout<< detectCapitalUse(s);
}

bool detectCapitalUse(string word) {
    int count = 0, len = word.size();

    if(len == 1)
        return true;

    for(int i = 0; i < len; i++)
    {
        if(isupper(word[i]))
            count++;
    }

    if(count == 1 && isupper(word[0]))
        return true;
    if(count == len || count == 0)
        return true;
    return false;
}