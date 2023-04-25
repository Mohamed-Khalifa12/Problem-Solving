#include <iostream>
#include <queue>
#include <set>

using namespace std;

class SmallestInfiniteSet
{
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    set<int> s;
public:
    SmallestInfiniteSet();
    int popSmallest();
    void addBack(int num);
};

