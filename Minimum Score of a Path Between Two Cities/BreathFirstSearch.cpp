#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minScore(int n, vector<vector<int>>& roads);
int getMin(vector<vector<pair<int,int>>> adj, int n);

int main()
{
    vector<vector<int>> roads = {{1,2,9},{2,3,6},{2,4,5},{1,4,7}};
    int result = minScore(4, roads);
    cout << result;

}

int minScore(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int,int>>> adj (n+1);
    //reconstruct the data intered in tha adj vector
    for(auto& road : roads)
    {
        adj[road[0]].push_back({road[1], road[2]});
        adj[road[1]].push_back({road[0], road[2]});
    }

    return getMin(adj, n);
}

int getMin(vector<vector<pair<int,int>>> adj, int n)
{
    int minScore = INT_MAX;
    vector<bool> isVisted (n+1);
    queue<int> q;

    q.push(1);
    isVisted[1] = true;

    while (!q.empty())
    {
        int value = q.front();
        q.pop();

        for(auto& node: adj[value])
        {
            minScore = min(minScore, node.second);
            if(!isVisted[node.first])
            {
                q.push(node.first);
                isVisted[node.first] = true;
            }
        }
    }
    return minScore;
}