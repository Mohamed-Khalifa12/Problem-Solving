#include "SmallestInfiniteSet.h"

int main()
{
    SmallestInfiniteSet* sm = new SmallestInfiniteSet();
    sm->addBack(2);
    cout<< sm->popSmallest() << "\n";
    cout<< sm->popSmallest() << "\n";
    cout<< sm->popSmallest() << "\n";
    sm->addBack(1);
    cout<< sm->popSmallest() << "\n";
    cout<< sm->popSmallest() << "\n";
    cout<< sm->popSmallest() << "\n";
}