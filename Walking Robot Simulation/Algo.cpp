int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int x = 0, y = 0, n = commands.size();
    unordered_map<string, int>mp;
    for(auto it: obstacles)
    {
        string str = to_string(it[0]) + "," + to_string(it[1]);
        mp[str]++;
    }
    int maxDis = 0;
    vector<vector<int>> directions = {{0, 1},{1, 0},{0,-1},{-1,0}};
    int dir = 0;

    for(int i = 0; i < n; i++)
    {
        if(commands[i] == -1)
        {
            dir = (dir + 1) % 4;
        }
        else if(commands[i] == -2)
        {
            dir--;
            if(dir == -1)
                dir = 3;
        }
        else
        {
            for(int j = 0; j < commands[i]; j++)
            {
                int newX = x + directions[dir][0];
                int newY = y + directions[dir][1];
                
                string key = to_string(newX) + "," + to_string(newY);
                if(mp.find(key) != mp.end())
                    break;
                x = newX, y = newY;
            }
            maxDis = max(x*x + y*y, maxDis);
        }
    }

    return maxDis;
}


