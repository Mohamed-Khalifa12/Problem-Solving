#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minReorder(int n, vector<vector<int>>& connections);
void bsf(vector<vector<pair<int, int>>> &adj, vector<bool> &isVisited, int &count);

int main()
{
    vector<vector<int>> connections = {{0,1},{1,3},{2,3},{4,0},{4,5}};
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
    vector<bool> isVisited (n);
    bsf(adj, isVisited, count);
    return count;
}

void bsf(vector<vector<pair<int, int>>> &adj, vector<bool> &isVisited, int &count)
{
    queue<int> q;
    q.push(0);

    while(!q.empty())
    {
        int node = q.front();
        isVisited[node] = true;
        q.pop();

        for(auto& [child, sign] : adj[node])
        {
            if(!isVisited[child])
            {
                count += sign;
                q.push(child);
            }
        }
    }
}