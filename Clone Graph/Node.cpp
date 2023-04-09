#include "Node.h"

Node::Node()
{
    val = 0;
    neighbors = vector<Node*>();
}

Node::Node(int _val)
{
    val = _val;
    neighbors = vector<Node*>();
}

Node::Node(int _val, vector<Node*> _neighbors)
{
    val = _val;
    neighbors = _neighbors;
}
