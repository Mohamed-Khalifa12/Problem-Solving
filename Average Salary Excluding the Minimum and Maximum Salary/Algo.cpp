#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

double average(vector<int>& salary);

int main() {
    vector<int> salary = {4000,3000,1000,2000};
    double avg = average(salary);
    cout<< avg;
}

double average(vector<int>& salary) {
    sort(salary.begin(), salary.end());
    int length = salary.size();
    int sum = 0;
    for(int i = 1; i < length - 1; i++)
        sum += salary[i];

    return (double) sum/ (length - 2);
}