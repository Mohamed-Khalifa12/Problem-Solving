#include<iostream>
#include<vector>

using namespace std;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges);

int main() {
    vector<vector<int>> edges = {{0,1},{2,1},{3,1},{1,4},{2,4}};
    vector<int> result = findSmallestSetOfVertices(5, edges);
    
    for(int val: result)
        cout<< val << "\t";
}

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> result;
    vector<bool> isComingEdgeExists (n, false);

    for(auto& edge : edges)
        isComingEdgeExists[edge[1]] = true;

    for(int i = 0; i < n; i++)
    {
        if(!isComingEdgeExists[i])
            result.push_back(i);
    }

    return result;
}