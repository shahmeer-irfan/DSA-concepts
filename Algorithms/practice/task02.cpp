//23k-0832
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

int lengthTailRecursive(Node *head, int count)
{
    if (head == nullptr)
    {
        return count;
    }
    return lengthTailRecursive(head->next, count + 1); // Tail recursion
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    int len = lengthTailRecursive(head, 0);
    cout << "Length of the linked list: " << len << endl;

    return 0;
}
