#include<iostream>
#include<vector>

using namespace std;

bool isBipartite(vector<vector<int>>& graph);
bool validColouring(vector<vector<int>>& graph, vector<int>& color, int node, int col);

int main() {
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    bool result = isBipartite(graph);
    cout<< result;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, 0);

    for(int node = 0; node < n; node++)
    {
        if(color[node] == 0 && !validColouring(graph, color, node, 1))
            return false;
    }
    return true;
}

bool validColouring(vector<vector<int>>& graph, vector<int>& color, int node, int col)
{
    if(color[node] != 0)
        return col == color[node];

    color[node] = col;
    for(int neighbour : graph[node])
    {
        if(!validColouring(graph, color, neighbour, -col))
            return false;
    }

    return true;
}