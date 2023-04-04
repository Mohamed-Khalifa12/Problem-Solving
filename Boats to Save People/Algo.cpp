#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numRescueBoats(vector<int>& people, int limit);

int main()
{
    vector<int> people = {1,2};
    int result = numRescueBoats(people, 3);

    cout<< result;
}

int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int start = 0; int end = people.size() - 1;
    int counter = 0;

    while(start <= end)
    {
        if(people[start] + people[end] <= limit)
            start++;
        end--;
        counter++;
    }

    return counter;
}