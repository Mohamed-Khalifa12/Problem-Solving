#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int indexofSmallestElement(int array[], int size);
void buildPalindrome(string &halfstr, int length);
string nearestPalindromic(string n);

int main()
{

    string str = "123";
    cout << nearestPalindromic(str) << endl;
}


string nearestPalindromic(string n) {
    int len = n.size();
    if(len == 1)
        return to_string(n[0] - '0' - 1);

    string halfstr = "";
    for(int i = 0; i < (len + 1)/2; i++)
        halfstr += n[i];

    string halflower = to_string(stoll(halfstr) - 1);
    string halfupper = to_string(stoll(halfstr) + 1);
    string limitup = to_string((long long)pow(10, len) + 1);
    string limitdown = to_string((long long)pow(10, (len-1)) - 1);

    buildPalindrome(halflower, len);
    buildPalindrome(halfupper, len);
    buildPalindrome(halfstr, len);

    string palindromeCandidates[5] = {halflower, halfstr, halfupper, limitdown, limitup};

    long long nearestPalindrome = 0;
    long long minDifference = LLONG_MAX;
    
    for (int i = 0; i < 5 ; i++) {
        long long candidate = stoll(palindromeCandidates[i]);
        if (candidate == stoll(n)) continue;
        long long difference = abs(candidate - stoll(n));
        if (difference < minDifference || (difference == minDifference && candidate < nearestPalindrome)) {
            minDifference = difference;
            nearestPalindrome = candidate;
        }
    }
    
    return to_string(nearestPalindrome);
}

void buildPalindrome(string &halfstr, int length)
{
    for(int i = 0; i < length/2; i++)
    {
        halfstr += halfstr[length/2 - i -1];
    }
}