int chalkReplacer(vector<int>& chalk, int k) {
    long long sumChalks = 0;
    for(int i = 0; i < chalk.size(); i++)
        sumChalks += chalk[i];

    int totalRemCh = k % sumChalks;

    for(int k = 0; k < chalk.size(); k++)
    {
        if(totalRemCh < chalk[k])
            return k;
        
        totalRemCh -= chalk[k];
    }
    return 0;
}