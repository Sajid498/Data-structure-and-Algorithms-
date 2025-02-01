#include<iostream>
using namespace std;

class Queue
{
    int rear,frnt,Size;
    int *s;
public:
    Queue()
    {
        Size=4;
        rear=frnt=-1;
        s=new int[Size];
    }
    Queue(int n)
    {
        Size=n;
        rear=frnt=-1;
        s=new int[n];
    }
    int isFull()
    {
        if( (rear+1)%Size == frnt ) return 1;
        else return 0;
    }
    int isEmpty()
    {
        if( rear==-1 && frnt == -1 ) return 1;
        else return 0;
    }
    void enqueue(int x)
    {
        if(isEmpty())
        {
            frnt=rear=0;
            s[rear]=x;
        }
        else if(isFull())
        {
            cout<<"queue is full"<<endl;
        }
        else
        {
            rear=(rear+1)%Size;
            s[rear]=x;
        }
    }
    int dequeue()
    {
        if( isEmpty() )
        {
            cout<<"queue is empty"<<endl;
            return INT_MAX;
        }
        else if( frnt == rear )
        {
            int y=s[frnt];
            frnt=rear=-1;
            return y;
        }
        else
        {
            int y=s[frnt];
            frnt=(frnt+1)%Size;
            return y;
        }
    }
    /*void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" <<endl;
            return;
        }

        cout << "Queue elements: "<<endl;
        for (int i=0;i<s.Size();i++)
        {
            cout<<s[i]<< " ";
        }
        cout<<endl;
    }*/


};

int main()
{
    // Create a queue of size 5
    Queue q(5);

    // Insert elements into the queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Try to insert one more element (should indicate queue is full)
    q.enqueue(60);

    // Display the queue elements
   // q.display();

    // Remove elements from the queue
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    // Display the queue after dequeue operations
    //q.display();

    return 0;

}
