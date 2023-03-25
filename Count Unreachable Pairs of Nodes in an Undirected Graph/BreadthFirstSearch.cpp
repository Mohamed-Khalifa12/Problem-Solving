#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int bfs(vector<vector<int>> &adj, int node, vector<bool> &isVisited);
long long countPairs(int n, vector<vector<int>>& edges);

int main()
{
    vector<vector<int>> edges = {{0,2},{0,5},{2,4},{1,6},{5,4}};
    long long val = countPairs(7, edges);
    cout<< val;
}

long long countPairs(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj (n);

    for(auto& edge: edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    long long countPairsValue = 0;
    long long sizeOfComponent = 0;
    long long restOfComponent = n;

    vector<bool> isVisited (n);
    for(int i = 0; i < n; i++)
    {
        if(!isVisited[i])
        {
            sizeOfComponent = bfs(adj, i, isVisited);
            countPairsValue += sizeOfComponent*(restOfComponent - sizeOfComponent);
            restOfComponent -= sizeOfComponent;
        }
    }
    return countPairsValue;
}

int bfs(vector<vector<int>> &adj, int node, vector<bool> &isVisited)
{
    int count = 1;
    queue<int> q;
    q.push(node);
    isVisited[node] = true;

    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        for(int neigbour : adj[val])
        {
            if(!isVisited[neigbour])
            {
                count++;
                q.push(neigbour);
                isVisited[neigbour] = true;
            }
        }
    }

    return count;
}