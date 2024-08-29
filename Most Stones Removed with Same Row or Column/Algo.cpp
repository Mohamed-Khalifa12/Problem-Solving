int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    int group = 0;

    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i, n, stones, visited);
            group++;
        }
    }

    return n - group;
}

void dfs(int k, int n, vector<vector<int>>& stones, vector<bool>& visited)
{
    visited[k] = true;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            if((stones[k][0] == stones[i][0]) || (stones[k][1] == stones[i][1]))
                dfs(i, n, stones, visited);
        }
    }
}