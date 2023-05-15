#include<iostream>
#include "Linked_List.h"

using namespace std;

ListNode* swapNodes(ListNode* head, int k);
void Print(ListNode *head);

int main() {
    ListNode* List = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* editted = swapNodes(List, 2);

    Print(editted);
}

ListNode* swapNodes(ListNode* head, int k) {
    ListNode* leftptr = head; ListNode* rightptr = head;
    ListNode* endptr;

    for(int i = 0; i < k - 1; i++)
        rightptr = rightptr->next;

    endptr = rightptr;
    while(rightptr->next != NULL) {
        leftptr = leftptr->next;
        rightptr = rightptr->next;
    }

    swap(endptr->val, leftptr->val);
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
