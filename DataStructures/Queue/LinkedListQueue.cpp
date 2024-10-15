#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *front; // Points to the front node
    Node *rear;  // Points to the rear node

public:
    // Constructor
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Destructor
    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue(); // Clean up all nodes when the queue is destroyed
        }
    }

    // Enqueue operation
    void enqueue(int value)
    {
        Node *newNode = new Node(value); // Create a new node with the given value

        if (isEmpty())
        {
            front = rear = newNode; // If the queue is empty, both front and rear will point to the new node
        }
        else
        {
            rear->next = newNode; // Add the new node at the end of the queue
            rear = newNode;       // Update rear to point to the new last node
        }

        cout << value << " enqueued to queue." << endl;
    }

    // Dequeue operation
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Return error value
        }

        int value = front->data; // Get the value of the front node
        Node *temp = front;      // Store the current front in a temporary node
        front = front->next;     // Move front to the next node

        // If the front becomes null, the queue is now empty, so set rear to null as well
        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp; // Delete the old front node to free memory
        return value;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Display elements in the queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        Node *temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr)
        {
            cout << temp->data << " "; // Print the data of each node
            temp = temp->next;         // Move to the next node
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

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
