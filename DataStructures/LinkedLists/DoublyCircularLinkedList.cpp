#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // Constructor
    Node(int value)
    {
        data = value;
        next = prev = nullptr;
    }
};

class DoublyCircularLinkedList
{
private:
    Node *head;
    Node *tail; // Tail pointer to the last node

public:
    // Constructor
    DoublyCircularLinkedList()
    {
        head = tail = nullptr; // Initialize both head and tail to nullptr
    }

    // Insert at the end
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode;                   // Initialize both head and tail with the new node
            newNode->next = newNode->prev = newNode; // Point to itself
        }
        else
        {
            tail->next = newNode; // Link the new node after tail
            newNode->prev = tail; // Link tail to new node
            newNode->next = head; // Link new node to head
            head->prev = newNode; // Link head back to new node
            tail = newNode;       // Update tail to the new node
        }
        cout << value << " inserted at the end." << endl;
    }

    // Insert at the beginning
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode;                   // Initialize both head and tail with the new node
            newNode->next = newNode->prev = newNode; // Point to itself
        }
        else
        {
            newNode->next = head; // New node points to head
            newNode->prev = tail; // New node points to tail
            head->prev = newNode; // Head's previous points to new node
            tail->next = newNode; // Tail's next points to new node
            head = newNode;       // Update head to the new node
        }
        cout << value << " inserted at the beginning." << endl;
    }

    // Delete a node
    void deleteNode(int value)
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;
        do
        {
            if (temp->data == value)
            {
                if (temp == head && head->next == head)
                { // Single node case
                    delete head;
                    head = tail = nullptr; // Both head and tail become nullptr
                }
                else
                {
                    Node *prevNode = temp->prev;
                    Node *nextNode = temp->next;
                    prevNode->next = nextNode; //linking nodes
                    nextNode->prev = prevNode;
                    if (temp == head)
                        head = nextNode; // If head is being deleted
                    if (temp == tail)
                        tail = prevNode; // If tail is being deleted
                    delete temp;
                }
                cout << value << " deleted." << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << value << " not found." << endl;
    }

    // Display the list
    void display()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        cout << "List: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main()
{
    DoublyCircularLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.display();
    list.deleteNode(20);
    list.display();
    list.deleteNode(5);
    list.display();
    list.deleteNode(10);
    list.display();
    return 0;
}
