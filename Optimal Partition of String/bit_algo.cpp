#include<iostream>
using namespace std;

int partitionString(string s);

int main()
{
    int parts = partitionString("ssssss");
    cout<< parts;
}

int partitionString(string s) {
    int counter = 1;
    int mask = 0;
    int i = 0;

    while(s[i] != '\0')
    {
        int shift = s[i] - 'a';
        if((mask & (1<<shift)) > 0)
        {
            counter++;
            mask = 0;
        }
        mask |= 1<<shift;
        i++;
    }

    return counter;
}