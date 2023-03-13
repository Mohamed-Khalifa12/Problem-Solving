#include <iostream>
#include <vector>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists);
bool check(vector<ListNode*>& lists, int length);
int min(vector<ListNode*>& lists, int length);

int main()
{
    vector<ListNode*> lists;
    ListNode *one = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode *two = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *three = new ListNode(2, new ListNode(6));
    lists.push_back(one);
    lists.push_back(two);
    lists.push_back(three);

    ListNode *result = mergeKLists(lists);
    while (result)
    {
        cout<< result->val << "\t";
        result = result->next;
    }
    
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int length = lists.size();
    if(length == 0)
        return nullptr;
    if(length == 1)
        return lists[0];
    if(check(lists, length))
        return nullptr;
    int val = min(lists, length);
    ListNode *result = new ListNode(val , mergeKLists(lists));
    return result;
}

int min(vector<ListNode*>& lists, int length)
{
    int min = lists[0]? lists[0]->val :INT_MAX;
    int index = 0;
    for(int i = 1; i < length; i++)
    {
        if((lists[i]? lists[i]->val : INT_MAX) < min)
        {
            min = lists[i]->val;
            index = i;
        }
    }
    lists[index] = lists[index]->next;
    return min;
}

bool check(vector<ListNode*>& lists, int length)
{
    for(int i = 0; i < length; i++)
    {
        if(lists[i] != nullptr)
            return false;
    }
    return true;
}