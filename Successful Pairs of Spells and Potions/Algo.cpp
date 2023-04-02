#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success);

int main()
{
    vector<int> spells = {5,1,3};
    vector<int> potions = {1,2,3,4,5};
    vector<int> output = successfulPairs(spells, potions, 7);
    for(int out : output)
    {
        cout<< out << "\t";
    }
}

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());
    vector<int> result;
    int length = potions.size();

    for(int spell : spells)
    {
        int start = 0; int end = potions.size() - 1;
        int index = length;
        while(start <= end)
        {
            int mid = (start + end)/2;
            if(spell*(long long)potions[mid] >= success)
            {
                end = mid - 1;
                index = mid;
            }
            else
                start = mid + 1;
        }
        result.push_back(length - index);
    }
    return result;
}