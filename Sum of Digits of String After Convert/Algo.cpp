
int getLucky(string s, int k) {
    string new_s = convert(s);
    int sum = 0;
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < new_s.size(); j++)
            sum += new_s[j] - '0';
        if(i != k - 1)
        {
            new_s = to_string(sum);
            sum = 0;
        }
    }
    return sum;
}

string convert(string s) {
    string str = "";
    int length = s.size();
    for(int i = 0; i < length; i++)
        str += to_string(s[i] - 'a' + 1);
    return str;
}

