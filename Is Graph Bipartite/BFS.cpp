#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool isBipartite(vector<vector<int>>& graph);

int main() {
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    bool result = isBipartite(graph);
    cout<< result;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> colour(n, 0);

    for(int node = 0; node < n; node++)
    {
        if(colour[node] != 0) 
            continue;
        
        colour[node] = 1;
        queue<int> q;
        q.push(node);

        while(!q.empty())
        {
            int current = q.front();
            q.pop();
            for(int neighbour : graph[current])
            {
                if(colour[neighbour] == 0)
                {
                    colour[neighbour] = -colour[current];
                    q.push(neighbour);
                }
                else if(colour[neighbour] == colour[current])
                    return false;
            }

        }
    }

    return true;
}