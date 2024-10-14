//23k-0832
#include <iostream>

using namespace std;

class Stack
{
    int top;
    int *array;
    
    int cap;

public:
    // Parameterized constructor
    Stack(const int size)
    {
        cap = size;
        array = new int[size];
        top = -1;
    }

    // Default constructor
    Stack()
    {
        array = nullptr; // Use nullptr instead of null
        top = -1;
        cap = 0;
    }

    // Copy constructor
    Stack(const Stack &other) : cap(other.cap), top(other.top)
    {
        array = new int[cap]; // Allocate memory for array
        for (int i = 0; i <= top; i++)
        {
            array[i] = other.array[i];
        }
    }

    // Destructor
    ~Stack()
    {
        delete[] array;
    }

    // Check if stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Check if stack is full
    bool isFull()
    {
        return top == cap - 1;
    }

    // Push element to stack
    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack is full!" << endl;
            return;
        }
        array[++top] = value;
    }

    // Pop element from stack
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1; // Return an invalid value
        }
        return array[top--];
    }

    // Peek top element of stack
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1; // Return an invalid value
        }
        return array[top];
    }

    // Display elements of stack
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << array[i] << endl;
        }
    }

    // Get current size of the stack
    int size()
    {
        return top + 1; // Since top is zero-based index, add 1
    }
};

int main()
{
    Stack stack(5); // Initialize stack with size 5
    stack.push(2);
    stack.push(3);
    stack.push(5);

    cout << "Stack elements:" << endl;
    stack.display();

    cout << "Current stack size: " << stack.size() << endl; // Use size function

    cout << "Popped element: " << stack.pop() << endl;
    cout << "Top element after pop: " << stack.peek() << endl;

    cout << "Current stack size: " << stack.size() << endl; // Check size after popping

    return 0;
}
