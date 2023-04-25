#include "SmallestInfiniteSet.h"

SmallestInfiniteSet::SmallestInfiniteSet()
{
    for(int i = 0; i <= 1000; i++)
    {
        pq.push(i);
        s.insert(i);
    }
}

int SmallestInfiniteSet::popSmallest()
{
    int top = pq.top();
    pq.pop();
    auto it = s.find(top);
    if(it != s.end())
        s.erase(it);
    
    return top;
}

void SmallestInfiniteSet::addBack(int num)
{
    if(s.insert(num).second)
    {
        pq.push(num);
    }
}