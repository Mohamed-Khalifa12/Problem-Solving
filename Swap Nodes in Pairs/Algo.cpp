#include<iostream>
#include"Linked_List.h"

using namespace std;

ListNode* swapPairs(ListNode* head);
void Print(ListNode *head);

int main () {
    ListNode* List = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* editted = swapPairs(List);

    Print(editted);
}

ListNode* swapPairs(ListNode* head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    ListNode* first = head;
    ListNode* second = head->next;

    while(first && second)
    {
        swap(first->val, second->val);
        first = first->next->next;
        if(second->next)
            second = second->next->next;
    }
    return head; 
}

void Print(ListNode *head)
{   
    ListNode* tracker = head;
    while(tracker) {
        cout << tracker->val << endl;
        tracker = tracker->next;
    }
}