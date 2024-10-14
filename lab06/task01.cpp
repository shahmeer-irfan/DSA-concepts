#include <iostream
using namespace std;

class Stack
{
public:
    int size;
    int top;
    int *array;

    Stack(const int size)
    {
        this->size = size;
        array = new int[size];
        top = -1;
    }

    // Default constructor
    Stack()
    {
        array = nullptr; // Use nullptr instead of null
        top = -1;
        this->size = 0;
    }

    // Copy constructor
    Stack(const Stack &other) : size(other.size), top(other.top)
    {
        array = new int[size]; // Allocate memory for array
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

    bool isFull()
    {
        return top == size - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack is Full." << endl;
            return;
        }

        array[++top] = value;
    }

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

    int getSize()

    {
        return size;
    }
};

int main()
{
    Stack stack(10);
    Stack stackEven(10);
    Stack stackOdd(10);

    stack.push(1);
    stack.push(3);
    stack.push(2);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);
    stack.push(10);

    for (int i = 0; i < stack.getSize(); i++)
    {
        int popValue = stack.pop();

        if (popValue % 2 == 0)
        {
            stackEven.push(popValue);
        }
        else
        {
            stackOdd.push(popValue);
        }
    }

    cout << "Even numbers in the stack:" << endl;
    stackEven.display();

    cout << "Odd numbers in the stack:" << endl;
    stackOdd.display();
    return 0;
}