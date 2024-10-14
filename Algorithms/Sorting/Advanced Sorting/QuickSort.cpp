// #include <iostream>

// using namespace std;

// class Node
// {
//     int data;
//     Node *next;
//     friend class LinkedList;

// public:
//     Node(int data) : data(data), next(nullptr) {};
//     Node() : data(0), next(nullptr) {};
// };

// class LinkedList
// {
//     Node *head;

// public:
//     LinkedList() : head(nullptr) {};
//     LinkedList(Node *n) : head(n) {};

//     // Insert at the front
//     void insertAtFront(int data)
//     {
//         Node *newNode = new Node(data);
//         newNode->next = head;
//         head = newNode;
//     }

//     // Insert at the end
//     void insertAtEnd(int data)
//     {
//         Node *newNode = new Node(data);
//         if (head == nullptr)
//         {
//             head = newNode;
//             return;
//         }

//         Node *temp = head;
//         while (temp->next != nullptr)
//         {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }

//     void swapData(Node *a, Node *b)
//     {
//         int temp = a->data;
//         a->data = b->data;
//         b->data = temp;
//     }


//     Node Partition(Node *pivot, Node *lb, Node *ub)
//     {
//         pivot = head;
//         Node *start = lb;
//         Node *end = ub;

//        Node *temp = head;
//        int count = 0;
//        while(temp->next!=nullptr)
//        {
//         if(temp->data)
//        }

//     }
// };
//     int main()
//     {
//         return 0;
//     }