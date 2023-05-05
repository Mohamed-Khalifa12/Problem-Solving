#include<iostream>

using namespace std;
int maxVowels(string s, int k);

bool isVowel(char c);

int main() {
    string s = "tryhard";
    int result = maxVowels(s, 4);
    cout << result;
}

int maxVowels(string s, int k) {
    int L = s.size(), vLength = 0, maxLength = 0;

    for(int i = 0; i < k; i++) {
        if(isVowel(s[i]))
            vLength++;
    } 

    maxLength = max(maxLength, vLength);
    if(maxLength >= k)
        return k;

    int start = 0, end = k - 1; 
    for(int i = end; i < L; i++) {
        if(isVowel(s[start++])) {vLength--;}
        if(isVowel(s[++end])) {vLength++;}
        maxLength = max(maxLength, vLength);
        if(maxLength >= k)
            return k;
    }

    return maxLength;
}

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}