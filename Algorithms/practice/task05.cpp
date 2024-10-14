//23k-0832
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

Node *rotate(Node *head, int k)
{
    if (!head || !head->next || k <= 0)
        return head;

    Node *current = head;
    int length = 1; // Length of the list

    while (current->next)
    {
        current = current->next;
        length++;
    }

    k = k % length; // Adjust k if it's greater than length
    if (k == 0)
        return head; // No rotation needed

    current->next = head; // Make the list circular

    Node *newHead = head;
    for (int i = 0; i < length - k - 1; i++)
    {
        newHead = newHead->next;
    }

    Node *temp = newHead->next; // Save the new head
    newHead->next = nullptr;    // Break the circular link
    return temp;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2; // Rotate by k places
    cout << "Original List: ";
    printList(head);

    head = rotate(head, k);
    cout << "Rotated List: ";
    printList(head);

    return 0;
}
