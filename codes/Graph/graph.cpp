#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next_link;
    Node *adjacent;
    Node *destination;

    Node(int data)
    {
        this->data = data;
        this->next_link = NULL;
        this->adjacent = NULL;
        this->destination = NULL;
    }

    Node(Node *destination)
    {
        this->data = 0;
        this->next_link = NULL;
        this->adjacent = NULL;
        this->destination = destination;
    }


};

int main()
{

    return 0;
}