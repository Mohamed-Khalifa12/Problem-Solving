#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *y): val(x), next(y){}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(0), left(left), right(right){}
};

TreeNode* sortedListToBST(ListNode* head);
void inOrderTraversal(TreeNode* node);

int main()
{
    ListNode *head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);

    TreeNode *result = sortedListToBST(head);
    inOrderTraversal(result);
}

TreeNode* sortedListToBST(ListNode* head) {
    if(head == nullptr)
        return nullptr;
    if(head->next == nullptr)
        return new TreeNode(head->val);
    
    ListNode* slow = head;
    ListNode* fast = head->next->next;

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    TreeNode *result = new TreeNode(slow->next->val);
    result->right = sortedListToBST(slow->next->next);
    //Disconnect the left half from the List
    slow->next = nullptr;
    result->left = sortedListToBST(head);
    return result;
}

void inOrderTraversal(TreeNode* node)
{
    if(node == nullptr)
        return;
    inOrderTraversal(node->left);
    cout<< node->val << "\t";
    inOrderTraversal(node->right);
}

