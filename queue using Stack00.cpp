#include<iostream>
#include<stack>
using namespace std;
class Queue
{
    stack<int> s;
public:
    Queue()
    {

    }
    void enqueue(int x)
    {
        s.push(x);
    }
    bool isEmpty()
    {
        return s.empty();
    }
    int dequeue()
    {
        if( isEmpty() )
        {
            cout<<"queue is empty"<<endl;
            return INT_MAX;
        }
        stack<int> temp;
        while( !s.empty() )
        {
            int x=s.top();
            temp.push(x);
            s.pop();
        }
        int y=temp.top();
        temp.pop();

        while ( !temp.empty() )
        {
            int z=temp.top();
            s.push(z);
            temp.pop();
        }
        return y;
    }
};


int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout << q.dequeue() << " "<<endl;
    cout <<  q.dequeue() << " "<<endl;
    cout <<  q.dequeue() << " "<<endl;
    cout  << q.dequeue() << " "<<endl;


    return 0;
}
