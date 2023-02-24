#include <stdio.h>
#include <string.h>

char* strcopy(char s[]);

int main()
{
    int x = -121;
    char *num, *rev;
    sprintf(num, "%d", x);
    rev = strcopy(num);

    //reversing rev var
    strrev(rev);

    //comparing between the number (in string) & the rev number (in string)
    if(!strcmp(num, rev))
        printf("The number is palindrome");
    else    
        printf("The number is not palindrome");  
}

char* strcopy(char s[])
{
    char *s2 = strdup(s);
    return s2;
}