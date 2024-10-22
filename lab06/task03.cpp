//23k-0832
#include <iostream>
using namespace std;

class TicketQueue
{
private:
    int front;
    int rear;
    int size;
    int *queueArray;
    int capacity;

public:
    // Constructor to initialize the queue with a fixed size
    TicketQueue(int capacity)
    {
        this->capacity = capacity;
        queueArray = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor to release memory
    ~TicketQueue()
    {
        delete[] queueArray;
    }

    // Check if the queue is full
    bool isFull()
    {
        return size == capacity;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Enqueue operation: Add passenger to the queue
    void enqueue(int passengerId)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot add more passengers." << endl;
            return;
        }

        rear = (rear + 1) % capacity; // Circular behavior to prevent index overflow
        queueArray[rear] = passengerId;
        size++;
        cout << "Passenger " << passengerId << " added to the queue." << endl;
    }

    // Dequeue operation: Remove passenger from the queue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. No passengers to remove." << endl;
            return;
        }

        cout << "Passenger " << queueArray[front] << " removed from the queue." << endl;
        front = (front + 1) % capacity; // Circular behavior for the queue
        size--;
    }

    // Display the queue status
    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Current queue: ";
        for (int i = 0; i < size; i++)
        {
            int index = (front + i) % capacity;
            cout << queueArray[index] << " ";
        }
        cout << endl;
    }
};

int main()
{
    TicketQueue ticketQueue(10); // Initialize queue with a capacity of 10

    // Adding 10 passengers to the queue
    for (int i = 1; i <= 10; i++)
    {
        ticketQueue.enqueue(i);
    }

    ticketQueue.displayQueue();

    // Removing the first 5 passengers
    for (int i = 0; i < 5; i++)
    {
        ticketQueue.dequeue();
    }

    ticketQueue.displayQueue();

    // Attempt to add 5 more passengers
    for (int i = 11; i <= 15; i++)
    {
        ticketQueue.enqueue(i);
    }

    ticketQueue.displayQueue();

    return 0;
}
