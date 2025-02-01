#include<iostream>
#include<stack>
using namespace std;

class Stack
{
    int n=0;
    queue<int> q1,q2;
public:
    Stack()
    {
        n=0;
    }
    void push(int x)
    {
        q2.push(x);
        n++;
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
       queue <int> t=q1;
        q1=q2;
        q2=t;
    }
};
