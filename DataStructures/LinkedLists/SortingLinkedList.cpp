#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor for Node
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;

    // Constructor for LinkedList
    LinkedList() : head(nullptr) {}

    // Insert a new node at the beginning of the list
    void insert(int val)
    {
        Node *newNode = new Node(val); // Create new node

        if (head == nullptr)
        {
            head = newNode; // Set head to newNode if list is empty
        }
        else
        {
            newNode->next = head; // Link newNode to head
            head = newNode;       // Update head to newNode
        }
    }

    // Bubble sort implementation to sort the list
    void bubbleSort()
    {
        if (head == nullptr || head->next == nullptr) // If list is empty or has one element
            return;

        bool swapped = true;
        while (swapped)
        {
            swapped = false;
            Node *temp = head; //initializing inside because loop will restart from head in every iteration

            while (temp->next != nullptr)
            {
                if (temp->data > temp->next->data)
                {
                    // Swap the data between nodes
                    int curr = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = curr;
                    swapped = true;
                }
                temp = temp->next; // Move to the next node
            }
        }
    }

    void selectionSort()
    {
        if (head == nullptr || head->next == nullptr) // If list is empty or has one element
            return;

        Node *current = head;
        while(current != NULL)
        {
            Node *minPtr = current;
            Node *temp  = current->next;

            while(temp != NULL)
            {
                if(minPtr->data > temp->data)
                {
                    minPtr = temp;
                }

                temp = temp->next;
            }

            if(minPtr!=current)
            {
                int swap = current->data;
                current->data = minPtr->data;
                minPtr->data = swap;
            }

            current = current->next;
        }
    }

    // Print the entire list
    void printList()
    {
        Node *temp = head;
        int count = 1;

        if (temp == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        while (temp != nullptr)
        {
            cout << "Value " << count << ": " << temp->data << endl;
            temp = temp->next;
            count++;
        }
    }

    void insertionSort()
    {
        Node *current = head; // index i
            Node *prev = NULL;

        while(current!=NULL)
        {
            int key = current->next->data;
            prev = current;

            while(prev!=NULL && prev->data > key)
            {
                prev
            }
        }
    }
};

int main()
{
    LinkedList list;

    // Inserting values into the list
    list.insert(5);
    list.insert(3);
    list.insert(8);
    list.insert(1);
    list.insert(7);

    // Print the list before sorting
    cout << "Linked list before sorting:" << endl;
    list.printList();

    // Sort the list using bubble sort
    //list.bubbleSort();
    list.selectionSort();

    // Print the list after sorting
    cout << "\nLinked list after sorting:" << endl;
    list.printList();

    return 0;
}
