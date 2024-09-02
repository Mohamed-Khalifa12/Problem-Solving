
vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    if (m * n != original.size()) {
        return {}; 
    }

    vector<vector<int>> arr(m, vector<int>(n, 0));
    int k = 0, l = 0;

    for(int i = 0; i < original.size(); i++)
    {

        if(i % n == 0 && i != 0)
        {
            k++;
            l = 0;
        }
        arr[k][l] = original[i];
        l++;
    }

    return arr;
}

