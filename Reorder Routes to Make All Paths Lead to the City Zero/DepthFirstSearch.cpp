#include <iostream>
#include <vector>
using namespace std;

int minReorder(int n, vector<vector<int>>& connections);
void dsf(vector<vector<pair<int, int>>> &adj, int parent , int node, int &count);

int main()
{
    vector<vector<int>> connections = {{1,0},{1,2},{3,2},{3,4}};
    int result = minReorder(6, connections);
    cout<< result;
}

int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<pair<int, int>>> adj (n);
    for(auto& connection: connections)
    {
        adj[connection[0]].push_back({connection[1], 1});
        adj[connection[1]].push_back({connection[0], 0});
    }
    int count = 0;
    dsf(adj, -1, 0, count);
    return count;
}

void dsf(vector<vector<pair<int, int>>> &adj, int parent , int node, int &count)
{
    for(auto& [child, sign] : adj[node])
    {
        if(parent != child)
        {
            count += sign;
            dsf(adj, node, child, count);
        }
    }
}