#include "Node.h"

class WordDictionary
{
private:
    Node *arrLL[26];
    int hashing(string word);
    void pushNode(int index, string word);
    bool searchLL(int index, string word);
    bool isEqualString(string str1, string str2);
public:
    WordDictionary();
    void addWord(string word);
    bool search(string word);
};
