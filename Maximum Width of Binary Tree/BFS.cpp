#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int widthOfBinaryTree(TreeNode* root);

int main()
{
    TreeNode* leftSubtree = new TreeNode(3,  new TreeNode(5), new TreeNode(3));
    TreeNode* rightSubtree = new TreeNode(2, nullptr, new TreeNode(9));
    TreeNode* root = new TreeNode(1, leftSubtree, rightSubtree);

    int result = widthOfBinaryTree(root);
    cout<< result;
}

int widthOfBinaryTree(TreeNode* root) {
    if(root == nullptr) return 0;

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int maxLength = 1;

    while (!q.empty())
    {
        int size = q.size();
        int front = q.front().second;
        int back = q.back().second;

        maxLength = max(maxLength, back - front + 1);
        for(int i = 0; i < size; i++)
        {
            auto frontElement = q.front();
            TreeNode* node = frontElement.first;
            int currentIndex = frontElement.second;
            int index = currentIndex - front;

            q.pop();

            if(node->left)
                q.push({node->left, index*2LL+1});
            
            if(node->right)
                q.push({node->right, index*2LL+2});
        }
    }
    
    return maxLength;
}