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
void summer(TreeNode* root, string str, int &sum);

int main(){
    TreeNode *tree = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
    int sum = sumNumbers(tree);
    cout << sum;
}

int sumNumbers(TreeNode* root) {
    int sum = 0;
    summer(root, "", sum);
    return sum;
}

void summer(TreeNode* root, string str, int &sum)
{
    if(root == nullptr)
        return;
    str += to_string(root->val);
    if(root->left == nullptr && root->right == nullptr)
    {
        sum += stoi(str);
        return;
    }
    summer(root->left, str, sum);
    summer(root->right, str, sum);
}