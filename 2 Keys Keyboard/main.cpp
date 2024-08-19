#include <iostream>
using namespace std;

int minSteps(int n) ;

int main()
{
    int n;
    cout << "Please Enter the Number: ";
    cin >> n;

    int result = minSteps(n);
    cout << "The result = " << result;
}

int minSteps(int n) {
    int factor = 2, steps = 0;
    while(n > 1)
    {
        if(n % factor == 0)
        {
            steps += factor;
            n /= factor;
        }
        else
        {
            factor++;
        }
    }

    return steps;
}