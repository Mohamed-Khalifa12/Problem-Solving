int mySqrt(int x) {
    unsigned long long i;
    for(i = 0; i < ULLONG_MAX; i++)
    {
        if(i * i > x)
            break;
    }

    return i - 1;
}