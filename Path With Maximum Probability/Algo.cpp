
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    vector<pair<int,double>> adj[n];

    for(int i=0 ; i<edges.size() ;i++){
        adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
        adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
    }

    vector<double> prob(n, 0.0);
    prob[start_node] = 1;

    queue<pair<int, double>> q;
    q.push({start_node, 1});

    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        for(auto neighbour:adj[it.first])
        {   
            double probMult = neighbour.second*it.second;
            if(prob[neighbour.first] < probMult)
            {
                prob[neighbour.first] = probMult;
                q.push({neighbour.first, prob[neighbour.first]});
            }
        }
    }

    return prob[end_node];
    
}
