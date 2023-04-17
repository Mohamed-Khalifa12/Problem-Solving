#include<iostream>
#include<vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies);

int main()
{
    vector<int> candies = {2,3,5,1,3};
    vector<bool> result = kidsWithCandies(candies, 3);

    for(bool val: result)
        cout<<val<< "\t"; 
}

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> result(candies.size());
    int maxCandies = 0;
    int i = 0;
    for(int candy: candies)
    {
        maxCandies = max(maxCandies, candy);
    }

    for(int candy: candies)
    {
        if(candy + extraCandies >= maxCandies)
            result[i] = true;
        i++;
    }

    return result;
}