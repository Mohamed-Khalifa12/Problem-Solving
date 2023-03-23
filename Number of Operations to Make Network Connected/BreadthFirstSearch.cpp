#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int makeConnected(int n, vector<vector<int>>& connections);
void bfs(vector<vector<int>> &adj, int node, vector<bool> &isVisited);

int main()
{
    vector<vector<int>> v = {{0,1},{0,2},{0,3},{1,2}};
    int result = makeConnected(6, v);
    cout<< result;
}

int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size() < n-1 )
        return -1;
    
    vector<vector<int>> adj (n);
    for(auto& connection: connections)
    {
        adj[connection[0]].push_back(connection[1]);
        adj[connection[1]].push_back(connection[0]);
    }

    int NumberofConnected = 0;
    vector<bool> isVisited (n);
    for(int i = 0; i < n; i++)
    {
        if(!isVisited[i])
        {
            NumberofConnected++;
            bfs(adj, i, isVisited);
        }
    }
    return NumberofConnected - 1;
}

void bfs(vector<vector<int>> &adj, int node, vector<bool> &isVisited)
{
    queue<int> q;
    q.push(node);
    isVisited[node] = true;

    while (!q.empty())
    {
        int value = q.front();
        q.pop();
        for(int& neighbour: adj[value])
        {
            if(!isVisited[neighbour])
            {
                q.push(neighbour);
                isVisited[neighbour] = true;
            }
        }
    }  
}