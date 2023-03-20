#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n);

int main()
{
    vector<int> v = {0,0,0,0,0,1,0,0};
    bool result = canPlaceFlowers(v, 2);
    cout << result;
}

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if(n == 0)
        return true;
    for(int i = 0; i < flowerbed.size(); i++)
    {
        if(flowerbed[i])
            continue;
        if((i-1 == -1 ? 0 : flowerbed[i-1]) == 0 && (i+1 == flowerbed.size() ? 0 : flowerbed[i+1]) == 0)
        {
            n--;
            flowerbed[i] == 1;
        }
        if(!n)
            return true;
    }
    return false;
}