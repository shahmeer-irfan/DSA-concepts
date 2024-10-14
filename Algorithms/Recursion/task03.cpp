//23k-0832
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;

    LinkedList() : head(nullptr) {}

    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    Node *reverseRecursive(Node *current)
    {
        if (current == nullptr || current->next == nullptr)
        {
            return current;
        }

        Node *newHead = reverseRecursive(current->next);

        current->next->next = current;
        current->next = nullptr;

        return newHead;
    }

    void reverse()
    {
        head = reverseRecursive(head);
    }

    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);

    cout << "Original Linked List: ";
    ll.printList();

    ll.reverse();

    cout << "Reversed Linked List: ";
    ll.printList();

    return 0;
}
