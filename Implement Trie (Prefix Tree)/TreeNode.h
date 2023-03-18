#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string value;
    Node *left;
    Node *right;

    Node(string val);
};
