#include <iostream>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;

ListNode *detectCycle(ListNode *head);

int main()
{
    ListNode first(1);
    ListNode second(2);
    ListNode third(3);
    ListNode forth(4);

    first.next = &second;
    second.next = &third;
    third.next = &second;

    ListNode *result = detectCycle(&first);
    result ? cout << result->val : cout << "NULL";
}

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            slow = head;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}