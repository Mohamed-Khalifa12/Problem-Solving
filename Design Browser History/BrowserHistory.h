#include "Node.h"

class BrowserHistory
{
private:
    Node *root;
    Node *pointer;
    void intializeBrowser();
    void push(string value);
    string pop();
    string stepForward();
public:
    BrowserHistory(string homepage);
    void visit(string url);
    string back(int steps);
    string forward(int steps);
};

