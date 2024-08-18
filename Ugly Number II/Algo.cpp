#include <iostream>
using namespace std;

int nthUglyNumber(int n);

int main(){
    int result = nthUglyNumber(150);
    cout << "150th ugly no. is " << result << endl;
}

int maxDiv(int x, int y)
{
    while(x % y == 0)
        x = x / y;

    return x;
}

int isUgly(int num)
{
    num = maxDiv(num, 2);
    num = maxDiv(num, 3);
    num = maxDiv(num, 5);

    return (num == 1) ? 1 : 0;
}

int nthUglyNumber(int n) {
    int uglyCount = 0, i = 0;

    while(uglyCount < n)
    {
        if(isUgly(++i))
            uglyCount++;
    }

    return i;
}
