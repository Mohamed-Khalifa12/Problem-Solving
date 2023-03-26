#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestCycle(vector<int>& edges);
void dfs(int node, vector<int>& edges, unordered_map<int, int> &dist, vector<bool> &isVisited, int &result);

int main()
{
    vector<int> edges = {3,3,4,2,3};
    int result = longestCycle(edges);
    cout<< result;
}

void dfs(int node, vector<int>& edges, unordered_map<int, int> &dist, vector<bool> &isVisited, int &result)
{
    isVisited[node] = true;
    int neighbour = edges[node];

    if(neighbour != -1 && !isVisited[neighbour])
    {
        dist[neighbour] = dist[node] + 1;
        dfs(neighbour, edges, dist, isVisited, result);
    }
    else if(neighbour != -1 && dist.count(neighbour))
    {
        result = max(result, dist[node] - dist[neighbour] + 1);
    }
}

int longestCycle(vector<int>& edges) {
    int n = edges.size();
    vector<bool> isVisited (n);
    int result = -1;
    for(int i = 0; i < n; i++)
    {
        if(!isVisited[i])
        {
            unordered_map<int, int> dist;
            dist[i] = 1;
            dfs(i, edges, dist, isVisited, result);
        }
    }
    return result;
}
