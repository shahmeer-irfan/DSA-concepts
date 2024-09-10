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

    void insert(const int data)
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

    void segregate()
    {
        if (!head || !head->next)
            return;

        Node *evenStart = nullptr, *evenEnd = nullptr;
        Node *oddStart = nullptr, *oddEnd = nullptr;
        Node *temp = head;

        while (temp != nullptr)
        {
            Node *nextNode = temp->next; // Save next node before manipulating temp

            if (temp->data % 2 == 0) // Even node
            {
                if (evenStart == nullptr)
                {
                    evenStart = evenEnd = temp; // Initialize even list
                }
                else
                {
                    evenEnd->next = temp; // Append to the even list
                    evenEnd = evenEnd->next;
                }
            }
            else // Odd node
            {
                if (oddStart == nullptr)
                {
                    oddStart = oddEnd = temp; // Initialize odd list
                }
                else
                {
                    oddEnd->next = temp; // Append to the odd list
                    oddEnd = oddEnd->next;
                }
            }

            temp->next = nullptr; // Disconnect the current node
            temp = nextNode;      // Move to the next node in the original list
        }

        // If there are no even nodes, the odd list becomes the head
        if (evenStart == nullptr)
        {
            head = oddStart;
        }
        else
        {
            // Connect even list to odd list
            evenEnd->next = oddStart;
            head = evenStart;
        }

        // Ensure the last odd node points to nullptr
        if (oddEnd != nullptr)
        {
            oddEnd->next = nullptr;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl; // End of the list
    }
};

int main()
{
    LinkedList list;
    list.insert(17);
    list.insert(15);
    list.insert(8);
    list.insert(12);
    list.insert(10);
    list.insert(5);
    list.insert(4);
    list.insert(1);
    list.insert(7);
    list.insert(6);

    cout << "Original List:" << endl;
    list.display();

    list.segregate();

    cout << "Segregated List (Even followed by Odd):" << endl;
    list.display();

    return 0;
}
