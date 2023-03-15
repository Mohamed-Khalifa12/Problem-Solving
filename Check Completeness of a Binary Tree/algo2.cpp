#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int countNodes(TreeNode *root);
bool checkCom(TreeNode *root, int index, int n);
bool isCompleteTree(TreeNode* root);

int main(){
    TreeNode *tree = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3,  new TreeNode(6), new TreeNode(7)));
    bool result = isCompleteTree(tree);
    cout << result;
}

int countNodes(TreeNode *root)
{
    if(root == nullptr)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool checkCom(TreeNode *root, int index, int n)
{
    if(root == nullptr)
        return true;
    
    if(index >= n)
        return false;
    
    return checkCom(root->left, index*2 +1, n) && checkCom(root->right, index*2+2, n);
}

bool isCompleteTree(TreeNode* root)
{
    return checkCom(root, 0, countNodes(root));
}