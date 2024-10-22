//23k-0832
#include <iostream>
#include <string>
#include <algorithm> // reversing function keylye hai
using namespace std;

// Manually implemented stack class
class Stack
{
private:
    char *arr;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        arr = new char[size];
        top = -1;
        capacity = size;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(char value)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = value;
    }

    char pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    char peek()
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

// Function to determine precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix to postfix
string infix_to_postfix(string infix)
{
    Stack stack(infix.length());
    string postfix;

    for (char c : infix)
    {
        // If the character is an operand, add it to the output
        if (isalnum(c))
        {
            postfix += c;
        }
        // If the character is '(', push it to the stack
        else if (c == '(')
        {
            stack.push(c);
        }
        // If the character is ')', pop and add to output until '(' is found
        else if (c == ')')
        {
            while (!stack.isEmpty() && stack.peek() != '(')
            {
                postfix += stack.pop();
            }
            stack.pop(); // Pop '(' from stack
        }
        // If the character is an operator
        else if (isOperator(c))
        {
            while (!stack.isEmpty() && precedence(c) <= precedence(stack.peek()))
            {
                if (c == '^' && stack.peek() == '^')
                    break; // Right to left associativity for ^
                postfix += stack.pop();
            }
            stack.push(c);
        }
    }

    // Pop all remaining operators from the stack
    while (!stack.isEmpty())
    {
        postfix += stack.pop();
    }

    return postfix;
}

// Function to reverse the string and swap '(' with ')'
string reverse_infix(string infix)
{
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }
    return infix;
}

// Function to convert infix to prefix
string infix_to_prefix(string infix)
{
    // Step 1: Reverse the infix expression and swap parentheses
    string reversed_infix = reverse_infix(infix);

    // Step 2: Get the postfix of the reversed expression
    string postfix = infix_to_postfix(reversed_infix);

    // Step 3: Reverse the postfix to get the prefix expression
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main()
{
    string infix = "K+L-M*N+(O^P)*W/U/V*T+Q";

    // Convert infix to postfix
    string postfix = infix_to_postfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    // Convert infix to prefix
    string prefix = infix_to_prefix(infix);
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
