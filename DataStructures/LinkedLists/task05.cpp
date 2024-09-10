//23k-0832
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void insert(int value)
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

    void sort()
    {
        if (head == nullptr)
            return;

        Node *temp, *nextNode;
        bool swapped;
        do
        {
            swapped = false;
            temp = head;
            while (temp->next != nullptr)
            {
                nextNode = temp->next;
                if (temp->data > nextNode->data)
                {
                    int tempData = temp->data;
                    temp->data = nextNode->data;
                    nextNode->data = tempData;
                    swapped = true;
                }
                temp = nextNode;
            }
        } while (swapped);
    }

    void removeDuplicates()
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        while (temp != nullptr)
        {
            Node *nextNode = temp->next;
            while (nextNode != nullptr && nextNode->data == temp->data)
            {
                Node *duplicateNode = nextNode;
                nextNode = nextNode->next;
                if (duplicateNode == tail)
                {
                    tail = temp; // Update tail if last duplicate
                }
                delete duplicateNode; // Remove duplicate
            }
            temp->next = nextNode;
            if (nextNode != nullptr)
            {
                nextNode->prev = temp;
            }
            temp = temp->next;
        }
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
        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << "-";
                
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    // Insert random values into the list
    for (int i = 0; i < 10; ++i)
    {
        int randomValue = rand() % 20; // Random values between 0 and 19
        list.insert(randomValue);
    }

    cout << "Original List:" << endl;
    list.display();

    list.sort();
    cout << "Sorted List:" << endl;
    list.display();

    list.removeDuplicates();
    cout << "List after removing duplicates:" << endl;
    list.display();

    return 0;
}
