//23k-0832
#include <iostream>
using namespace std;
class Node
{
    int data;
    Node *next;
    friend class LinkedList;

public:
    Node(int data) : data(data), next(nullptr) {};
    Node() : data(0), next(nullptr) {};
};

class LinkedList
{
    Node *head;

public:
    LinkedList() : head(nullptr) {};
    LinkedList(Node *n) : head(n) {};

    // Insert at the front
    void insertAtFront(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert before a specific value
    void insertBefore(int value, const int insertValue)
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *newNode = new Node(insertValue);

        if (head->data == value)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;
        Node *previousPtr = nullptr;

        while (temp != nullptr && temp->data != value)
        {
            previousPtr = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Value not found in the list.\n";
            delete newNode;
            return;
        }

        newNode->next = temp;
        previousPtr->next = newNode;
    }

    // Insert after a specific value
    void insertAfter(int value, const int insertValue)
    {
        Node *temp = head;
        while (temp != nullptr && temp->data != value)
        {
            temp = temp->next;
        }

        if (temp != nullptr)
        {
            Node *newNode = new Node(insertValue);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else
        {
            cout << "There is no node with the given value.\n";
        }
    }

    // Delete from head
    void deleteFromHead()
    {
        if (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            cout << "List is empty.\n";
        }
    }

    // Delete from end
    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete a node with a specific value
    void deleteNodeParticularValue(int value)
    {
        if (head == nullptr)
        {
            cout << "List is already empty.\n";
            return;
        }

        if (head->data == value)
        {
            deleteFromHead();
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != value)
        {
            temp = temp->next;
        }

        if (temp->next == nullptr)
        {
            cout << "Value not found in the list.\n";
        }
        else
        {
            Node *tempNode = temp->next;
            temp->next = temp->next->next;
            delete tempNode;
        }
    }

    // Reverse the linked list
    void ReverseLinkList()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    // Count the number of nodes
    void countNodes()
    {
        Node *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        cout << "Total number of nodes: " << count << endl;
    }

    // Print the list
    void printList()
    {
        Node *temp = head;
        int count = 1;
        while (temp != nullptr)
        {
            cout << "Value " << count << ": " << temp->data << endl;
            temp = temp->next;
            count++;
        }
    }
};

int main()
{
    LinkedList list;

    list.insertAtFront(10);
    list.insertAtFront(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Original List:\n";
    list.printList();

    list.insertBefore(30, 25);
    cout << "\nList after inserting 25 before 30:\n";
    list.printList();

    list.insertAfter(40, 50);
    cout << "\nList after inserting 50 after 40:\n";
    list.printList();

    list.deleteFromEnd();
    cout << "\nList after deleting from the end:\n";
    list.printList();

    list.deleteNodeParticularValue(25);
    cout << "\nList after deleting node with value 25:\n";
    list.printList();

    cout << "\nReversing the list...\n";
    list.ReverseLinkList();
    list.printList();

    list.countNodes();

    return 0;
}
