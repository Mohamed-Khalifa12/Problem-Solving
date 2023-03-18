#include "Trie.h"
// THE MAIN REQUIRED FUNCTIONS
Trie::Trie()
{
    root = nullptr;
}

void Trie::insert(string word)
{
    if(root == nullptr)
    {
        root = new Node(word);
        return;
    }
    Node *temp = root;
    Node *new_node = new Node(word);
    while(temp != nullptr)
    {
        if(is_string_less(word, temp->value))
        {
            if(temp->left == nullptr)
            {
                temp->left = new_node;
                return;
            }
            temp = temp->left;
        }
        else
        {
            if(temp->right == nullptr)
            {
                temp->right = new_node;
                return;
            }
            temp = temp->right;
        }
    }
}

bool Trie::search(string word)
{
    return search_recrusion(root, word);
}

bool Trie::startsWith(string prefix)
{
    return startsWith_recrusion(root, prefix);
}

//THE HELPING FUNCTIONS
//helping function to find the node for starting with
bool Trie::startsWith_recrusion(Node *root, string prefix)
{
    if(root == nullptr)
        return false;
    if(is_part(prefix, root->value))
        return true;
    if(is_string_less(prefix, root->value))
        return(startsWith_recrusion(root->left, prefix));
    return(startsWith_recrusion(root->right, prefix));
}

bool Trie::is_part(string str1, string str2)
{
    string str2_new = str2.substr(0, str1.size());
    if(str2_new == str1)
        return true;
    return false;
}

//helping function to find the node for searching
bool Trie::search_recrusion(Node *root, string word)
{
    if(root == nullptr)
        return false;
    if(root->value == word)
        return true;
    if(is_string_less(word, root->value))
        return(search_recrusion(root->left, word));
    return(search_recrusion(root->right, word));
}

//helping function to check if the 1st string is less than 2nd string
bool Trie::is_string_less(string str1, string str2)
{
    for(int i = 0; i< str1.size() -1; i++)
    {
        if(str1[i] < str2[i])
            return true;
        if(str1[i] > str2[i])
            return false;
    }
    return true;
}

//Inorder Traversal for Tree
void Trie::printInorderTraversal()
{
    iorderTrav(root);
}

void Trie::iorderTrav(Node *root)
{
    if(root == nullptr)
        return;
    iorderTrav(root->left);
    cout << root->value << "\t";
    iorderTrav(root->right);
}