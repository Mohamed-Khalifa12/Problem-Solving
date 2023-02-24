#include <iostream>
using namespace std;

void str_reverse(string &rev, int length);
bool isPalindrome(int x);

int main()
{
    int x = 121;
    bool result = isPalindrome(x);
    cout<< result;
}

bool isPalindrome(int x)
{
    string a = to_string(x);
    string rev_a = a;
    int length = size(a);
    str_reverse(rev_a, length);
    if(a == rev_a)
        return true;
    return false;
}

void str_reverse(string &rev, int length)
{
    for(int i = 0; i < length/2; i++)
    {
        char temp = rev[i];
        rev[i] = rev[length-1-i];
        rev[length-1-i] = temp;
    }
}

