#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isCompleteTree(TreeNode* root);

int main(){
    TreeNode *tree = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3,  nullptr, new TreeNode(7)));
    bool result = isCompleteTree(tree);
    cout << result;
}


bool isCompleteTree(TreeNode* root) {
    queue <TreeNode *> q;
    q.push(root);
    bool isNullFound = false;

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if(node == nullptr)
            isNullFound = true;
        else
        {
            if(isNullFound)
                return false;
            q.push(node->left);
            q.push(node->right);
        }
    }
    return true;
}