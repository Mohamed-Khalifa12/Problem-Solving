vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    TraverseTree(root, result);
    return result;
}

void TraverseTree(TreeNode* root, vector<int>& res)
{
    if(root)
    {
        TraverseTree(root -> left, res);
        TraverseTree(root -> right, res);
        res.push_back(root-> val);
    }
}