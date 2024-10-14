//23k-0832
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class StackLinkedList
{
    Node *top;

public:
    StackLinkedList()
    {
        top = nullptr;
    }

    void push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (top == nullptr)
        {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        Node *temp = top;
        top = top->next;
        int poppedValue = temp->data;
        delete temp;
        return poppedValue;
    }

    int peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    ~StackLinkedList()
    {
        while (top != nullptr)
        {
            pop();
        }
    }
};

int main()
{
    StackLinkedList stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.peek() << endl;

    cout << "Popped element: " << stack.pop() << endl;
    cout << "Popped element: " << stack.pop() << endl;

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
