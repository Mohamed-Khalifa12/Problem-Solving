#include<iostream>
#include<vector>

using namespace std;

long long mostPoints(vector<vector<int>>& questions);
long long solve(vector<vector<int>>& questions, vector<int>& memo, int i);

int main() {
    vector<vector<int>> questions = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    long long result = mostPoints(questions);
    cout<< result;
}

long long mostPoints(vector<vector<int>>& questions) {
    vector<long long> memo (questions.size(), -1);
    return solve(questions, memo, 0);
}

long long solve(vector<vector<int>>& questions, vector<long long>& memo, int i)
{
    if (i >= questions.size())
        return 0;
    if(memo[i] != -1)
        return memo[i];
    memo[i] = max(questions[i][0] + solve(questions, memo, i + questions[i][1] + 1), solve(questions, memo, i + 1));
    return memo[i];
}