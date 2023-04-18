#include<iostream>

using namespace std;

string mergeAlternately(string word1, string word2);

int main()
{
    string word1 = "abcd", word2 = "pq";
    string result = mergeAlternately(word1, word2);
    cout<< result;
}

string mergeAlternately(string word1, string word2) {
    int i = 0, j = 0;
    string str;

    while(word1[i] != '\0' || word2[j] != '\0')
    {
        if(word1[i])
            str += word1[i++];
        if(word2[j])
            str += word2[j++];
    } 

    return str;
}