#include<iostream>
using namespace std;

struct node
{
    int value;
    node*next;
};
node*createNewnode(int x)
{
    node*newnode=new node;
    newnode->value=x;
    newnode->next=NULL;
    return newnode;
}
class Graph
{
    int nVertices;
    bool directed;
    node **adjlist;
public:
    for(int i=0;i<nVertices;i++)
    {

    }
};
