#include <iostream>

using namespace std;
/*This cpp file contains all the necessary functions that you can perform on Doubly Linked list with proper explaination*/


class Node
{
    int data;
    Node *next;
    Node *prev;
    friend class LinkedList;

public:
    Node(int data) : data(data), next(nullptr), prev(nullptr) {};
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtFront(const int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;  //it can also be written as newNode->next->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(const int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertBeforeValue(const int value, const int insertValue)
    {
        Node *newNode = new Node(insertValue);
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == value)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp != nullptr && temp->data != value)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Value not found!" << endl;
            return;
        }

        newNode->next = temp;
        newNode->prev = temp->prev;

        if (temp->prev != nullptr)
        {
            temp->prev->next = newNode;
        }
        temp->prev = newNode;
    }

    void deleteHead()
    {
        if (head == nullptr)
        {
            cout << "List is already empty!" << endl;
            return;
        }

        Node *temp = head;  //storing head in temp variable
        head = head->next; //shifting head to second node

        if (head != nullptr) //checking if second node exists
        {
            head->prev = nullptr;  //making prev pointer null
        }
        else
        {
            tail = nullptr; //if second node doesnt exist it means tail is also nullptr 
        }
        delete temp;  //deleting head.
    }

    void deleteLastNode()
    {
        if (tail == nullptr)
        {
            cout << "List is already empty!" << endl;
            return;
        }

        Node *temp = tail;
        tail = tail->prev;

        if (tail != nullptr)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete temp;
    }

    void deleteParticularNode(int value)
    {
        if (head == nullptr)
        {
            cout << "List is already empty!" << endl;
            return;
        }

        if (head->data == value)
        {
            deleteHead();
            return;
        }

        if (tail->data == value)
        {
            deleteLastNode();
            return;
        }

        Node *temp = head;
        while (temp != nullptr && temp->data != value)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Value not found!" << endl;
            return;
        }

        temp->prev->next = temp->next;  
        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    void display()
    {
        Node *temp = head;
        if (temp == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }
        cout << "Doubly Linked List: ";
        while (temp != nullptr)   //will iterate till last
        {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << " <-> ";
            temp = temp->next;   //traversing further
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    list.insertAtFront(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertBeforeValue(20, 15);
    list.display();
    list.deleteHead();
    list.display();
    list.deleteLastNode();
    list.display();
    list.deleteParticularNode(15);
    list.display();
    return 0;
}
