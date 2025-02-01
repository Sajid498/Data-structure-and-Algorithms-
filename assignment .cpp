#include <iostream>
using namespace std;

class Queue
{
public:
    int *q;
    int capacity;
    int f, r, Size;
    Queue()
    {
        q = new int[1];
        capacity = 1;
        f = Size = 0;
        r = -1;
    }

    void removeCirArray()
    {
        int index = 0;
        int *t = new int[capacity];
        for (int i =f; i < capacity; i++)
        {
            t[index++] = q[i];
        }
        for (int i = 0; i < f; i++)
        {
            t[index++] = q[i];
        }
        swap(q,t);
        delete[] t;
        f = 0;
        r = capacity - 1;
    }

    void increaseSize()
    {
        removeCirArray();
        int *t= new int[capacity * 2];
        for (int i = 0; i < capacity; i++)
        {
            t[i] = q[i];
        }
        swap(q, t);
        delete[] t;
        capacity *= 2;
    }

    void enqueue(int value)
    {
        if (Size == capacity)
        {
            increaseSize();
        }
        r++;
        if (r == capacity)
        {
            r = 0;
        }
        q[r] = value;
        Size++;
    }
    void dequeue()
    {
        if (Size == 0)
        {
            cout << "Queue is empty\n";
            return;
        }
        f++;
        if (f == capacity)
        {
            f = 0;
        }
        Size--;
    }
    int front()
    {
        if (Size == 0)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return q[f];
    }

    int size()
    {
        return Size;
    }
};

int main()
{
    Queue Q;

    Q.enqueue(5);
    Q.enqueue(6);
    Q.enqueue(7);

    cout << "Queue Size : " << Q.size() << "\n";
    cout << Q.front() << " ";
    Q.dequeue();
    cout << Q.front() << " ";
    Q.dequeue();
    cout << Q.front() << " ";
    Q.dequeue();

    cout << "\nQueue Size: " << Q.size() << "\n";


}

