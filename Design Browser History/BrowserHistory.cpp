#include "BrowserHistory.h"

BrowserHistory::BrowserHistory(string homepage)
{
    intializeBrowser();
    push(homepage);
}

void BrowserHistory::visit(string url)
{
    push(url);
}

string BrowserHistory::back(int steps)
{
    string val;
    for(int i = 0; i < steps; i++)
        val = pop();
    return val;
}

string BrowserHistory::forward(int steps)
{
    string val;
    for(int i = 0; i < steps; i++)
        val = stepForward();
    return val;
}

//HELPING FUNCTIONS
void BrowserHistory::intializeBrowser()
{
    root = nullptr;
    pointer = nullptr;
}

void BrowserHistory::push(string str)
{
    Node *new_node = new Node(str);
    if(!root)
    {
        root = new_node;
        pointer = root;
        return;
    }

    pointer->next = new_node;
    new_node->prev = pointer;
    pointer = new_node;
}

string BrowserHistory::pop()
{
    if(pointer->prev)
        pointer = pointer->prev;
    return pointer->value;
}

string BrowserHistory::stepForward()
{
    if(pointer->next)
        pointer = pointer->next;
    return pointer->value;
}