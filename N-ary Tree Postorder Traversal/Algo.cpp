vector<int> postorder(Node* root) {
    vector<int> result;
    postorderTrav(root, result);
    return result;
}

void postorderTrav(Node* root, vector<int> &result)
{
    if(root == NULL)
        return;
    for(int i = 0; i < (root->children).size(); i++)
        postorderTrav((root->children)[i], result);
    result.push_back(root->val);
}