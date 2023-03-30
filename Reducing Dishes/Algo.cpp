#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSatisfaction(vector<int>& satisfaction);

int main()
{
    vector<int> satisfaction = {-1,-8,0,5,-9};
    int result = maxSatisfaction(satisfaction);
    cout << result;
}

int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    
    int maxSatisfaction = 0;
    int suffixSum = 0;
    for (int i = satisfaction.size() - 1; i >= 0 && suffixSum + satisfaction[i] > 0; i--) {
        // Total satisfaction with all dishes so far.
        suffixSum += satisfaction[i];
        // Adding one instance of previous dishes as we add one more dish on the left.
        maxSatisfaction += suffixSum;
    }
    
    return maxSatisfaction;        
}