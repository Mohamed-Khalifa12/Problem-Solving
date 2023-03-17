#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTreeHelper(unordered_map <int, int> &mp, vector<int>& postorder, int &postIndex, int start, int end);
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
void inorderTravesal(TreeNode *tree);

int main()
{
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode *tree = buildTree(inorder, postorder);
    inorderTravesal(tree);
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int postIndex = postorder.size() - 1;
    unordered_map <int, int> mp;
    for(int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;
    return buildTreeHelper(mp, postorder, postIndex, 0, inorder.size() - 1);
}

TreeNode* buildTreeHelper(unordered_map <int, int> &mp, vector<int>& postorder, int &postIndex, int start, int end)
{
    if(start > end)
        return nullptr;
    int inorderIndex = mp[postorder[postIndex]];
    TreeNode *node = new TreeNode(postorder[postIndex]);
    postIndex--;

    node->right = buildTreeHelper(mp, postorder, postIndex, inorderIndex + 1, end);
    node->left = buildTreeHelper(mp, postorder, postIndex, start, inorderIndex - 1);
    return node;
}

void inorderTravesal(TreeNode *tree)
{
    if(tree == nullptr)
        return;
    inorderTravesal(tree->left);
    cout << tree->val << "\t";
    inorderTravesal(tree->right);
}