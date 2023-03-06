#include <iostream>
using namespace std;

string convert(string s, int numRows);

int main()
{
    string s = "PAYPALISHIRING";
    string converted = convert(s, 4);
    cout<< converted;
}

string convert(string s, int numRows) 
{
    string strVec[numRows];
    string newStr ;
    int length = s.size(), count = 0;

    if(numRows == 1)
        return s;
    while (count < length)
    {
        for (int i = 0; i < numRows; i++)
        {
            if(count < length)
                strVec[i] += s[count++];
            else
                break;
        }
        for (int i = numRows - 2; i > 0; i--)
        {
            if(count < length)
                strVec[i] += s[count++];
            else
                break;
        }
    }

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < strVec[i].size(); j++)
        {
            newStr += strVec[i][j];
        }   
    }
    
    return newStr;
}