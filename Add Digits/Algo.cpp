#include <iostream>
#include <string>

using namespace std;

int addDigits(int num);
int summer(string str);

int main()
{
    int result = addDigits(38);
    cout<< result;
}

int addDigits(int num) {
    if(num < 0)
        return num;

    while (num > 9)
    {
        string str = to_string(num);
        num = summer(str);
    }

    return num;
}

int summer(string str)
{
    int sum = 0, i = 0;

    while (str[i] != '\0')
    {
        sum += str[i] - '0';
        i++;
    }
    
    return sum;
}