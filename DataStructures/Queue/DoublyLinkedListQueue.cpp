#include <iostream>
using namespace std;

// Node class for the doubly circular linked list
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = prev = nullptr;
    }
};

// Doubly Circular Linked List class
class DoublyCircularLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyCircularLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Enqueue operation (insert at the end)
    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        { // If the list is empty
            head = newNode;
            tail = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        { // If the list is not empty
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode; // Update tail to the new node
        }
        cout << value << " enqueued to the queue." << endl;
    }

    // Dequeue operation (remove from the front)
    int dequeue()
    {
        if (!head)
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Indicating an error
        }

        int value = head->data; // Get the front item
        if (head == tail)
        { // If there's only one node
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        { // More than one node
            Node *temp = head;
            head = head->next; // Move head to the next node
            head->prev = tail; // Update new head's previous to point to tail
            tail->next = head; // Update tail's next to point to new head
            delete temp;       // Delete old head
        }
        cout << value << " dequeued from the queue." << endl;
        return value; // Return the dequeued value
    }

    // Check if the queue is empty
    bool isEmpty() const
    {
        return head == nullptr; // The queue is empty if head is null
    }

    // Display the queue elements
    void display() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        Node *temp = head;
        cout << "Queue elements: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Destructor to free allocated memory
    ~DoublyCircularLinkedList()
    {
        while (!isEmpty())
        {
            dequeue(); // Dequeue all elements
        }
    }
};

int main()
{
    DoublyCircularLinkedList queue; // Create a queue using doubly circular linked list

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();

    queue.dequeue();
    queue.display();

    queue.dequeue();
    queue.dequeue();
    queue.display(); // Should show that the queue is empty

    return 0;
}
