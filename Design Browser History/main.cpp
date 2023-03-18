#include "BrowserHistory.h"

int main()
{
    BrowserHistory *h = new BrowserHistory("leetcode.com");
    h->visit("google.com");
    h->visit("facebook.com");
    h->visit("youtube.com");
    string s1 = h->back(1);
    string s2 = h->back(1);
    string s3 = h->forward(1);
    h->visit("linkedin.com");
    string s4 = h->forward(2);
    string s5 = h->back(2);
    string s6 = h->back(7);

    cout << s1 << "\n" <<s2 << "\n" << s3 << "\n" <<s4 << "\n"<< s5 << "\n" <<s6 << "\n";  
}