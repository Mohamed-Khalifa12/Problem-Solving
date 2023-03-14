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

int sumNumbers(TreeNode* root);
int summer(TreeNode* root, int sumDepth);

int main(){
    TreeNode *tree = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
    int sum = sumNumbers(tree);
    cout << sum;
}

int sumNumbers(TreeNode* root)
{
    return summer(root, 0);
}

int summer(TreeNode* root, int sumDepth){
    if(root == nullptr)
        return 0;
    sumDepth = sumDepth*10 + root->val;
    if(root->left == nullptr && root->right == nullptr)
        return sumDepth;
    return summer(root->left, sumDepth) + summer(root->right, sumDepth);
}