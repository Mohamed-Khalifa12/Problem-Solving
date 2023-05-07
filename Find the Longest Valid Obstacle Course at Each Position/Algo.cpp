#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles);

int main() {
      vector<int> obstacles = {3,1,5,6,4,2};
      vector<int> result = longestObstacleCourseAtEachPosition(obstacles);
      for(int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
      }
}

vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
      int n = obstacles.size();
      vector<int> result(n), list;

      for(int i = 0; i < n; i++)
      {
            int idx = upper_bound(list.begin(), list.end(), obstacles[i]) - list.begin();
            if(idx == list.size())
                  list.push_back(obstacles[i]);
            else 
                  list[idx] = obstacles[i];
            result[i] = idx + 1;
      }

      return result;
}