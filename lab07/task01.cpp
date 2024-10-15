//23k-0382
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;

    Node(int val)
    {
        value = val;
        next = nullptr;
    }
};

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

Node *getTail(Node *head)
{
    while (head != nullptr && head->next != nullptr)
    {
        head = head->next;
    }
    return head;
}

void swapValues(Node *first, Node *second)
{
    int temp = first->value;
    first->value = second->value;
    second->value = temp;
}

Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
{
    Node *pivot = end;
    Node *previous = nullptr;
    Node *current = head;
    Node *tail = pivot;

    while (current != pivot)
    {
        if (current->value < pivot->value)
        {
            if ((*newHead) == nullptr)
            {
                (*newHead) = current;
            }
            previous = current;
            current = current->next;
        }
        else
        {
            if (previous != nullptr)
            {
                previous->next = current->next;
            }
            Node *temp = current->next;
            current->next = nullptr;
            tail->next = current;
            tail = current;
            current = temp;
        }
    }

    if ((*newHead) == nullptr)
    {
        (*newHead) = pivot;
    }

    (*newEnd) = tail;
    return pivot;
}

Node *quickSortRecursive(Node *head, Node *end)
{
    if (!head || head == end)
    {
        return head;
    }

    Node *newHead = nullptr;
    Node *newEnd = nullptr;

    Node *pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot)
    {
        Node *temp = newHead;
        while (temp->next != pivot)
        {
            temp = temp->next;
        }
        temp->next = nullptr;

        newHead = quickSortRecursive(newHead, temp);

        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecursive(pivot->next, newEnd);

    return newHead;
}

void quickSort(Node **headRef)
{
    (*headRef) = quickSortRecursive(*headRef, getTail(*headRef));
}

void insertNode(Node **headRef, int value)
{
    Node *newNode = new Node(value);
    if (*headRef == nullptr)
    {
        *headRef = newNode;
    }
    else
    {
        Node *temp = *headRef;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main()
{
    Node *head = nullptr;

    insertNode(&head, 10);
    insertNode(&head, 7);
    insertNode(&head, 8);
    insertNode(&head, 9);
    insertNode(&head, 1);
    insertNode(&head, 5);
    insertNode(&head, 3);

    cout << "Linked list before sorting: ";
    printList(head);

    quickSort(&head);

    cout << "Linked list after sorting: ";
    printList(head);

    return 0;
}
