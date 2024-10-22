//23k-0832
#include <iostream>
using namespace std;

// Node structure to represent each passenger
struct Node
{
    int passengerId;
    Node *next;

    Node(int id) : passengerId(id), next(nullptr) {}
};

// Linked list based TicketQueue class
class TicketQueue
{
private:
    Node *front;
    Node *rear;
    int size;

public:
    // Constructor to initialize an empty queue
    TicketQueue()
    {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Destructor to release all dynamically allocated nodes
    ~TicketQueue()
    {
        while (front != nullptr)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Enqueue operation: Add passenger to the end of the queue
    void enqueue(int passengerId)
    {
        Node *newNode = new Node(passengerId);

        // If queue is empty, the new node is both front and rear
        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        size++;
        cout << "Passenger " << passengerId << " added to the queue." << endl;
    }

    // Dequeue operation: Remove passenger from the front of the queue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. No passengers to remove." << endl;
            return;
        }

        Node *temp = front;
        cout << "Passenger " << front->passengerId << " removed from the queue." << endl;
        front = front->next;

        // If the queue is now empty, set rear to nullptr
        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;
        size--;
    }

    // Display the passengers in the queue
    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        Node *temp = front;
        cout << "Current queue: ";
        while (temp != nullptr)
        {
            cout << temp->passengerId << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Get the size of the queue
    int getSize()
    {
        return size;
    }
};

int main()
{
    TicketQueue ticketQueue;

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

    // Adding 5 more passengers
    for (int i = 11; i <= 15; i++)
    {
        ticketQueue.enqueue(i);
    }

    ticketQueue.displayQueue();

    return 0;
}
