#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> queryResults(int limit, vector<vector<int>>& queries);

int main()
{
    vector<vector<int>> queries = {{0,1}, {0,4}, {1,2}, {1,5}, {1,4}};
    vector<int> result = queryResults(1, queries);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

}

vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    int queSize = queries.size();
    vector<int> result(queSize, 0);
    unordered_map<int, int> queMapped, colors;

    for(int i = 0; i < queSize; i++)
    {
        if(queMapped.find(queries[i][0]) != queMapped.end())
        {
            colors[queMapped[queries[i][0]]]--;
            if(colors[queMapped[queries[i][0]]] == 0)
                colors.erase(queMapped[queries[i][0]]);
        }

        queMapped[queries[i][0]] = queries[i][1];
        colors[queries[i][1]]++;
        result[i] = min(colors.size(), queMapped.size());
    }
    return result;
}