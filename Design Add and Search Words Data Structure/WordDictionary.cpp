#include "WordDictionary.h"

WordDictionary::WordDictionary() {}

void WordDictionary::addWord(string word)
{
    int index = hashing(word);
    pushNode(&arrLL[index], word);
}

bool WordDictionary::search(string word)
{
    int index = hashing(word);
    if(index != -1)
        return searchLL(&arrLL[index], word);
    
    for(int i = 0; i < 26; i++)
    {
        if(searchLL(&arrLL[i], word))
            return true;
    }
    return false;
}

// helping functions

int WordDictionary::hashing(string word)
{
    if(word[0] == '.')
        return -1;
    return word[0] - 'a';
}

void WordDictionary::pushNode(Node **node, string word)
{
   Node *new_node = new Node(word);
   new_node->next = *(node);
   *node = new_node;
}

bool WordDictionary::searchLL(Node **node, string word)
{
    Node *temp = *node;

    while(temp)
    {
        if(isEqualString(word, temp->value))
            return true;
       temp = temp->next; 
    }
    return false;
}

bool WordDictionary::isEqualString(string str1, string str2)
{
    if(str1.size() != str2.size())
        return false;

    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] == str2[i] || str1[i] == '.')
            continue;
        return false;
    }
    return true;
}