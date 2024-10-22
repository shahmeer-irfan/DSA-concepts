//23k-0832
#include <iostream>
using namespace std;

// Manually implemented stack class
class Stack
{
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        arr = new int[size];
        top = -1;
        capacity = size;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int value)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if (top == -1)
        {
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

// Queue using two stacks
class Queue
{
private:
    Stack *stack1;
    Stack *stack2;

public:
    Queue(int size)
    {
        stack1 = new Stack(size);
        stack2 = new Stack(size);
    }

    ~Queue()
    {
        delete stack1;
        delete stack2;
    }

    // Enqueue operation (push to stack1)
    void enqueue(int value)
    {
        stack1->push(value);
    }

    // Dequeue operation
    int dequeue()
    {
        if (stack2->isEmpty())
        {
            if (stack1->isEmpty())
            {
                cout << "Queue is empty!" << endl;
                return -1;
            }

            // Move elements from stack1 to stack2
            while (!stack1->isEmpty())
            {
                stack2->push(stack1->pop());
            }
        }

        // Pop from stack2
        return stack2->pop();
    }

    bool isEmpty()
    {
        return stack1->isEmpty() && stack2->isEmpty();
    }
};

int main()
{
    Queue q(10);

    // Enqueue elements
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    // Dequeue elements
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    // Enqueue more elements
    q.enqueue(6);
    q.enqueue(7);

    // Dequeue remaining elements
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    return 0;
}
