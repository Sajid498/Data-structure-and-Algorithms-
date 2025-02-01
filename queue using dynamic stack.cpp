#include <iostream>
using namespace std;

class DynamicArrayQueue {
private:
    int* queue;  // Pointer to the dynamic array
    int capacity;  // Current capacity of the array
    int front;  // Index of the front element
    int rear;  // Index of the rear element
    int size;  // Current number of elements

    // Function to resize the array when it's full
    void resize() {
        int* newQueue = new int[capacity * 2];  // Create a new array with double the capacity
        for (int i = 0; i < size; i++) {
            newQueue[i] = queue[(front + i) % capacity];  // Copy elements to new array
        }
        delete[] queue;  // Free the old array memory
        queue = newQueue;
        front = 0;
        rear = size;
        capacity *= 2;  // Update the capacity
    }

public:
    // Constructor
    DynamicArrayQueue(int initialCapacity = 4) {
        capacity = initialCapacity;
        queue = new int[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    // Destructor to free memory
    ~DynamicArrayQueue() {
        delete[] queue;
    }

    // Enqueue operation (adds element to the end)
    void enqueue(int value) {
        if (size == capacity) {
            resize();  // Resize array if full
        }
        queue[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
    }

    // Dequeue operation (removes element from the front)
    int dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        int frontElement = queue[front];
        front = (front + 1) % capacity;
        size--;
        return frontElement;
    }

    // Peek operation (get the front element without removing it)
    int peek() const {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return queue[front];
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Get the size of the queue
    int getSize() const {
        return size;
    }
};

int main() {
    DynamicArrayQueue queue;

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    // Dequeue an element
    //cout << "Dequeued: " << queue.dequeue() << endl;  // Output: 10

    // Peek at the front element
    cout << "Front element: " << queue.peek() << endl;  // Output: 20

    // Size of the queue
    cout << "Queue size: " << queue.getSize() << endl;  // Output: 2

    return 0;
}

