#include <iostream>
using namespace std;

class Queue {
public:
    int *a;              // Array to hold the elements of the queue
    int arrayCapacity;    // Capacity of the array
    int l, r, sz;         // Left (l), Right (r) indices, and size (sz)

    Queue() {
        a = new int[1];   // Initialize the array with a capacity of 1
        arrayCapacity = 1;
        l = sz = 0;       // Initialize left index (l) and size (sz) to 0
        r = -1;           // Initialize right index (r) to -1
    }

    // Function to rearrange the array when circular behavior breaks the order
    void remove_CircularArray() {
        int index = 0;
        int *tmp = new int[arrayCapacity];
        for (int i = l; i < arrayCapacity; i++) {
            tmp[index++] = a[i];
        }
        for (int i = 0; i < l; i++) {
            tmp[index++] = a[i];
        }
        swap(a, tmp);     // Swap the new array with the original one
        delete[] tmp;
        l = 0;
        r = arrayCapacity - 1;
    }

    // Function to increase the size of the array when it's full
    void increaseSize() {
        remove_CircularArray();  // Fix any circular behavior before increasing size
        int *tmp = new int[arrayCapacity * 2];
        for (int i = 0; i < arrayCapacity; i++) {
            tmp[i] = a[i];
        }
        swap(a, tmp);
        delete[] tmp;
        arrayCapacity *= 2;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        if (sz == arrayCapacity) {
            increaseSize();  // Increase the size of the array if it's full
        }
        r++;
        if (r == arrayCapacity) {
            r = 0;  // Wrap around if r exceeds the array capacity
        }
        a[r] = value;
        sz++;
    }

    // Function to remove the front element from the queue
    void dequeue() {
        if (sz == 0) {
            cout << "Queue is empty\n";
            return;
        }
        l++;
        if (l == arrayCapacity) {
            l = 0;  // Wrap around if l exceeds the array capacity
        }
        sz--;
    }

    // Function to return the front element of the queue
    int front() {
        if (sz == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return a[l];
    }

    // Function to return the size of the queue
    int size() {
        return sz;
    }
};

int main() {
    Queue q;

    // Enqueue some integers
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    // Print the queue size
    cout << "Queue size is: " << q.size() << "\n";

    // Print and dequeue each element
    cout << q.front() << " ";
    q.dequeue();
    cout << q.front() << " ";
    q.dequeue();
    cout << q.front() << " ";
    q.dequeue();

    // Print the queue size after dequeuing
    cout << "\nQueue size is: " << q.size() << "\n";

    return 0;
}

