#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    vector<Node*> neighbors;
    
    Node();
    Node(int _val);
    Node(int _val, vector<Node*> _neighbors);
};

