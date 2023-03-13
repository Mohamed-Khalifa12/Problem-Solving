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

bool isSymmetric(TreeNode* root);
bool ismirror(TreeNode* left, TreeNode* right);
 
int main(){
    //TreeNode *tree = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    TreeNode *tree = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(3)), new TreeNode(2, nullptr, new TreeNode(3)));
    bool val = isSymmetric(tree);
    cout<< val;
}

bool isSymmetric(TreeNode* root) {
    if(root == nullptr)
        return true;
    return ismirror(root->left, root->right);
}

bool ismirror(TreeNode* left, TreeNode* right){
    if(right == nullptr && left == nullptr)
        return true;
    if(right == nullptr || left == nullptr)
        return false;
    return left->val == right->val && ismirror(left->left, right->right) && ismirror(left->right, right->left);
}