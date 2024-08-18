#include <iostream>
using namespace std;

int nthUglyNumber(int n);

int main(){
    int result = nthUglyNumber(150);
    cout << "150th ugly no. is " << result << endl;
}

int nthUglyNumber(int n){
    int arr[n];
    arr[0] = 1;
    int point1 = 0, point2 = 0, point3 = 0;

    for(int i = 1; i < n; i++)
    {
        arr[i] = min(arr[point1]*2, min(arr[point2]*3, arr[point3]*5));

        if(arr[i] == arr[point1]*2)   point1++;
        if(arr[i] == arr[point2]*3)   point2++;
        if(arr[i] == arr[point3]*5)   point3++;
    }

    return arr[n-1];
}

