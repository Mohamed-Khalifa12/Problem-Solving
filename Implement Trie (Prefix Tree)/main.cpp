#include "Trie.h"

int main()
{
    Trie *obj = new Trie();
    obj->insert("cucumber");
    obj->insert("zebra");
    obj->insert("anna");
    obj->insert("apple");
    bool val1 = obj->search("apple");
    bool val2 = obj->search("app");
    bool val3 = obj->startsWith("appl");
    obj->insert("app");
    bool val4 = obj->search("app");
    cout << val1 <<"\t"<< val2<< "\t" << val3<< "\t" << val4;
}