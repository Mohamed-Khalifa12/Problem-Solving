#include <iostream>
#include <vector>
using namespace std;

int minScore(int n, vector<vector<int>>& roads);
void getMin(vector<vector<pair<int,int>>> adj, int &minScore, int node, vector<bool> &isVisted);

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

    int value = INT_MAX;
    vector<bool> isVisted (n+1);

    getMin(adj, value, 1, isVisted);
    return value;
}

void getMin(vector<vector<pair<int,int>>> adj, int &minScore, int node, vector<bool> &isVisted)
{
    isVisted[node] = true;

    for(auto& element : adj[node])
    {
        minScore = min(minScore, element.second);
        if(!isVisted[element.first])
            getMin(adj, minScore, element.first, isVisted);
    }
}