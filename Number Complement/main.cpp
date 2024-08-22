#include <iostream>
using namespace std;

int findComplement(int num);

int main()
{
    int num = 5;
    int result = findComplement(num);
    cout << result << endl; 
}

int findComplement(int num) {
    int count = 0;

    for(int i = 0; i < sizeof(int)*8; i++)
    {
        if(num&(0x80000000>>i) && count == 0)
        {
            ++count;
        }

        if(count > 0)
        {
            num ^= (0x80000000>>i);
        }
    }

    return num;
}