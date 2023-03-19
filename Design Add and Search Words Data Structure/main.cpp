#include "WordDictionary.h"

int main()
{
    WordDictionary *w = new WordDictionary();
    w->addWord("ahmed");
    w->addWord("ali");
    w->addWord("basel");
    w->addWord("rana");
    w->addWord("aya");
    w->addWord("zyad");

    bool result = w->search("ahme");
    result ? cout << "true" :  cout << "False";

}