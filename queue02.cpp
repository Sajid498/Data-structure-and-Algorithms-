#include<iostream>
using namespace std;

class Queue
{
    int r,f,Size;
    int *s;
public:
    Queue()
    {
        Size=4;
        r=f=-1;
        s=new int[Size];
    }
    Queue(int n)
    {
        Size=n;
        r=f=-1;
        s=new int[Size];
    }
    int isEmpty()
    {
        if(r==-1&&f==-1)
        {
            return 1;
        }
        else
            return 0;
    }
    int isFull()
    {
        if((r+1)%Size==f)
        {
            return 1;
        }
        else
            return 0;
    }
    void enqueue(int x)
    {
        if(isFull())
        {
            cout<<"Queue is full"<<endl;
        }
        else if(isEmpty())
        {
            r=f=0;
            s[r]=x;
        }
        else
        {
            r=(r+1)%Size;
            s[r]=x;
        }
    }
    int dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is Full"<<endl;
            return INT_MAX;
        }
        else if(f=r)
        {
            int y=s[f];
            f=r=-1;

            return y;
        }
        else
        {
            int y=s[f];
            f=(f+1)%Size;
            return y;
        }
    }

};
int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout<<q.dequeue()<<" "<<endl;
    cout<<q.dequeue()<<" "<<endl;

}
