#include "TreeNode.h"

class Trie
{
private:
    Node *root;
    void iorderTrav(Node *root);
    bool is_string_less(string str1, string str2);
    bool search_recrusion(Node *root, string word);
    bool startsWith_recrusion(Node *root, string prefix);
    bool is_part(string str1, string str2);
public:
    Trie();
    void insert(string word);
    void printInorderTraversal();
    bool search(string word);
    bool startsWith(string prefix);
};

