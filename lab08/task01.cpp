// 23k-0832
// shahmeer irfan
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(NULL), right(NULL) {}
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

class BST
{
    Node *head;

public:
    BST() : head(NULL) {}
    BST(Node *nn) : head(nn)
    {
        nn->left = NULL;
        nn->right = NULL;
    }

    Node *insert(int data, Node *head)
    {
        if (head == NULL)
        {
            head = new Node(data);
        }
        else if (data < head->data)
        {
            head->left = insert(data, head->left);
        }
        else if (data > head->data)
        {
            head->right = insert(data, head->right);
        }
        return head;
    }

    string serialize(Node *root)
    {
        if (root == NULL)
        {
            return "NULL ";
        }
        return to_string(root->data) + " " + serialize(root->left) + serialize(root->right);
    }

    string getNextValue(const string &data, int &index)
    {
        string value = "";
        while (index < data.size() && data[index] != ' ')
        {
            value += data[index];
            index++;
        }
        index++;
        return value;
    }

    Node *deserialize(string &data, int &index)
    {
        string value = getNextValue(data, index);
        if (value == "NULL")
        {
            return NULL;
        }

        Node *node = new Node(stoi(value));
        node->left = deserialize(data, index);
        node->right = deserialize(data, index);
        return node;
    }

    void preOrder(Node *head)
    {
        if (head == NULL)
        {
            return;
        }
        cout << head->data << " ";
        preOrder(head->left);
        preOrder(head->right);
    }
};

int main()
{
    Node *newNode = new Node(5);
    BST b(newNode);
    b.insert(3, newNode);
    b.insert(2, newNode);
    b.insert(4, newNode);
    b.insert(7, newNode);
    b.insert(6, newNode);

    cout << "Original Tree Pre-Order Traversal: ";
    b.preOrder(newNode);
    cout << endl;

    string serializedTree = b.serialize(newNode);
    cout << "Serialized Tree: " << serializedTree << endl;

    int index = 0;
    Node *deserializedRoot = b.deserialize(serializedTree, index);

    cout << "Deserialized Tree Pre-Order Traversal: ";
    b.preOrder(deserializedRoot);
    cout << endl;

    return 0;
}
