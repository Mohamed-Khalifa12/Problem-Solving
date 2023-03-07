#include <iostream>
using namespace std;

int romanToInt(string s);

int main()
{
    int val = romanToInt("LVIII");
    cout << val;
}

int romanToInt(string s) {
    int result = 0 ,length = s.size();
    for (int i = 0; i < length; i++)
    {
        switch (s[i])
        {
        case 'I':
            if((s[i+1] == 'V' || s[i+1] == 'X')&& i+1 != length)
                result -= 1;
            else
                result += 1;
            break;
        case 'V':
            result += 5;
            break;
        case 'X':
            if((s[i+1] == 'L' || s[i+1] == 'C')&& i+1 != length)
                result -= 10;
            else
                result += 10;            
            break;
        case 'L':
            result += 50;
            break;
        case 'C':
            if((s[i+1] == 'D' || s[i+1] == 'M')&& i+1 != length)
                result -= 100;
            else
                result += 100;     
            break;
        case 'D':
            result += 500;
            break;
        case 'M':
            result += 1000;
            break;
        default:
            return -1;
            break;
        }
    }

    return result;
    
}