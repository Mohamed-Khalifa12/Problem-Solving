#include<iostream>
#include<vector>
#include "Linked_List.h"

using namespace std;

int pairSum(ListNode* head);

int main() {
    ListNode* List = new ListNode(5, new ListNode(4, new ListNode(2, new ListNode(1))));
    int max = pairSum(List);

    cout<< max;
}

int pairSum(ListNode* head) {
    ListNode* current = head;
    vector<int> values;

    while (current) {
        values.push_back(current->val);
        current = current->next;
    }

    int i = 0, j = values.size() - 1;
    int maximumSum = 0;
    while (i < j) {
        maximumSum = max(maximumSum, values[i] + values[j]);
        i++;
        j--;
    }

    return maximumSum;
}
