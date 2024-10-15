#include <iostream>
using namespace std;

class Queue
{
private:
    int front;    // Index of the front element
    int rear;     // Index of the rear element
    int capacity; // Maximum number of elements the queue can hold
    int *queue;   // Array to store queue elements

public:
    // Constructor to initialize the queue
    Queue(int size)
    {
        capacity = size;
        front = 0;
        rear = -1;
        queue = new int[capacity]; // Dynamically allocate array for the queue
    }

    // Destructor to free up memory
    ~Queue()
    {
        delete[] queue; // Release the dynamically allocated memory
    }

    // Enqueue operation to add an item to the queue
    void enqueue(int item)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue " << item << "." << endl;
            return;
        }
        // Circularly increment rear and add the new item
        rear = (rear + 1) % capacity;
        queue[rear] = item;
        cout << item << " enqueued to queue." << endl;
    }

    // Dequeue operation to remove an item from the queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Return error value
        }
        int item = queue[front]; // Get the front item
        // Circularly increment front to point to the next element
        front = (front + 1) % capacity;
        return item; // Return the dequeued item
    }

    // Check if the queue is empty
    bool isEmpty() const
    {
        return (front == (rear + 1) % capacity);
    }

    // Check if the queue is full
    bool isFull() const
    {
        return (rear + 1) % capacity == front;
    }

    // Display elements in the queue
    void display() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        // Traverse from front to rear in a circular manner
        for (int i = front; i != (rear + 1) % capacity; i = (i + 1) % capacity)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

// Main function to test the Queue class
int main()
{
    Queue q(5); // Create a queue with a capacity of 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    q.display();

    q.enqueue(60);
    q.display();

    return 0;
}
