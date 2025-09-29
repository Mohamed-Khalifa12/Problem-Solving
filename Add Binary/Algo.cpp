#include <iostream>
#include <algorithm>

using namespace std;

string addBinary(string a, string b);

int main()
{
    string x = "11";
    string y = "1111";

    string str = addBinary(x,y);

    cout<< str;
}

string addBinary(string a, string b) {
    int n = a.size() - 1, m = b.size() - 1, carry = 0, output = 0;
    string result = "";

    while (n >= 0 || m >= 0 || carry > 0)
    {
        int x = (n >= 0 ? a[n] - '0' : 0);
        int y = (m >= 0 ? b[m] - '0' : 0);

        output = x + y +carry;

        carry = output/2;
        output %= 2;

        n--; 
        m--;

        result += output + (int)'0';
    }
    reverse(result.begin(), result.end());
    return result;
}