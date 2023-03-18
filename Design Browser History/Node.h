#include <iostream>
using namespace std;

class Node
{
public:
    string value;
    Node *prev;
    Node *next;
    Node(string val);
};