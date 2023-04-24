#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int lastStoneWeight(vector<int>& stones);

int main(){
    vector<int> stones = {1};
    int result = lastStoneWeight(stones);
    cout<< result;
}

int lastStoneWeight(vector<int>& stones) {
    int n = stones.size();
    sort(stones.begin(), stones.end(), greater<int>());
    int i = 0;
    while (i < n - 1)
    {
        if (stones[i] == stones[i + 1])
        {
            stones[i + 1] = 0;
            i += 2;
        }
        else{
            stones[i + 1] = stones[i] - stones[i + 1];
            i++;
            sort(stones.begin() + i, stones.end(), greater<int>());
        } 
    }

    return stones[n - 1];  
}