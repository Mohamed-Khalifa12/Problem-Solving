#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int longestZigZag(TreeNode* root);
void help(TreeNode* root, int dir, int step);

int maxLength = 0;

int main(){
    //First Test

    // TreeNode* subtree = new TreeNode(1,nullptr,new TreeNode(1,nullptr,new TreeNode(1)));
    // TreeNode* root = new TreeNode(1,nullptr, new TreeNode(1,new TreeNode(1), new TreeNode(1,subtree, new TreeNode(1))));
    
    //Second Test
    TreeNode* subtree = new TreeNode(1, new TreeNode(1,nullptr, new TreeNode(1)), new TreeNode(1));
    TreeNode* root = new TreeNode(1, new TreeNode(1,nullptr,subtree), new TreeNode(1));

    int result = longestZigZag(root);
    cout<< result;
}

//left = 0 right = 1
int longestZigZag(TreeNode* root) {
    help(root, 0, 0);
    help(root, 1, 0);

    return maxLength;
}

void help(TreeNode* root, int dir, int step)
{
    if(root == nullptr)
        return;

    maxLength = max(maxLength, step);
    help(root->left, 0, dir? step + 1 :1);
    help(root->right, 1, dir?1:step + 1);
}