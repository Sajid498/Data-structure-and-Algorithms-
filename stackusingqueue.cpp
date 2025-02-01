#include<iostream>
#include<stack>

class Stack
{
    int n;
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
        Queue<int> t;
        t=q1;
        q1=q2;
        q2=t;
    }
    void pop()
    {
        q1.pop();
        n--;
    }
    int Front()
    {
        return q1.Front;
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;

}
