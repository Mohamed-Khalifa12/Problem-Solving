#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int mincostTickets(vector<int>& days, vector<int>& costs);

int main()
{
    vector<int> days = {1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> costs = {2,7,15};

    int result = mincostTickets(days, costs);
    cout<< result;
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int db[366];
    unordered_set<int> set;
    db[0] = 0;

    for(int day: days)
        set.insert(day);

    for(int i = 1; i <= 365; i++)
    {
        if(set.find(i) == set.end())
        {
            db[i] = db[i-1];
        }
        else
        {
            db[i] = min(db[i-1] + costs[0], min(db[max(0, i-7)] + costs[1], db[max(0, i-30)] + costs[2]));
        }
    }
    return db[365];
}