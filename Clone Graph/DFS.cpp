#include "Node.h"
#include<unordered_map>

Node* dfs(Node* node, unordered_map<Node*, Node*>& mp);
Node* cloneGraph(Node* node);

int main()
{
    //create the original graph
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* forth = new Node(4);

    vector<Node*> neighbours_1 = {second, third};
    vector<Node*> neighbours_2 = {first, third};
    vector<Node*> neighbours_3 = {second, forth};
    vector<Node*> neighbours_4 = {first, third};

    first->neighbors = neighbours_1;
    second->neighbors = neighbours_2;
    third->neighbors = neighbours_3;
    forth->neighbors = neighbours_4;

    // test the orignal graph
    cout<< first->neighbors[0]->val << "\t";
    cout<< first->neighbors[0]->neighbors[1]->val << "\t";
    cout<< first->neighbors[0]->neighbors[1]->neighbors[1]->val << "\t";
    cout<< first->neighbors[0]->neighbors[1]->neighbors[1]->neighbors[0]->val << endl;

    //use the clone function to make a copy of the orignal one
    Node* clonedGraph =  cloneGraph(first);

    // test the cloned graph
    cout<< clonedGraph->neighbors[0]->val << "\t";
    cout<< clonedGraph->neighbors[0]->neighbors[1]->val << "\t";
    cout<< clonedGraph->neighbors[0]->neighbors[1]->neighbors[1]->val << "\t";
    cout<< clonedGraph->neighbors[0]->neighbors[1]->neighbors[1]->neighbors[0]->val << endl;
}


Node* cloneGraph(Node* node)
{
    if(node == nullptr)
        return nullptr;
    if(node->neighbors.size() == 0)
        return new Node(node->val);
    
    unordered_map<Node*, Node*> mp;
    return dfs(node, mp);
}

Node* dfs(Node* node, unordered_map<Node*, Node*>& mp)
{
    Node* clone = new Node(node->val);
    mp[node] = clone;
    vector<Node*> neighbors;

    for(Node* it: node->neighbors)
    {
        if(mp.find(it) != mp.end()) //the value is already in the map
            neighbors.push_back(it);
        else
            neighbors.push_back(dfs(it, mp));
    }
    clone->neighbors = neighbors;
    return clone;
}
