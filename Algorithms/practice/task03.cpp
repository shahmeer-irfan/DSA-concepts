//23k-0832
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

bool searchValue(Node *head, int target)
{
    if (head == nullptr)
    {
        return false;
    }
    if (head->data == target)
    {
        return true; 
    }
    return searchValue(head->next, target); 
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    int target = 2;
    bool found = searchValue(head, target);
    cout << "Value " << target << (found ? " found in the linked list." : " not found in the linked list.") << endl;

    return 0;
}
