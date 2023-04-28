#include<iostream>
#include<vector>

using namespace std;

bool isSimillar(string& str1, string& str2);
void dfs(vector<vector<int>>& adj, vector<bool>& visit, int node);
int numSimilarGroups(vector<string>& strs);

int main()
{
    vector<string> strs = {"omv","ovm"};
    int result = numSimilarGroups(strs);
    cout<< result;

}

int numSimilarGroups(vector<string>& strs) {
    int n = strs.size();
    vector<vector<int>> adj(n);

    //Creating the Graph
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(isSimillar(strs[i], strs[j]))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    //visit the graph elements
    vector<bool> visit(n);
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(!visit[i])
        {
            dfs(adj, visit, i);
            count++;
        }
    }

    return count;
}

bool isSimillar(string& str1, string& str2) {
    int count = 0;
    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] != str2[i])
            count++;
    }

    return count == 2 || count == 0;
}

void dfs(vector<vector<int>>& adj, vector<bool>& visit, int node) {
    visit[node] = true;
    for(auto& neighbour: adj[node])
    {
        if(!visit[neighbour])
            dfs(adj, visit, neighbour);
    }
}