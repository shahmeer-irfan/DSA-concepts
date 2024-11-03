#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }

    Node *insert(int data, Node *root)
    {
        if (root == NULL)
        {
            root = new Node(data); // if we found an empty position, insert Node
            return root;
        }
        if (root->data == data)
        {
            return root;
        }
        else if (data < root->data)
        {
            root->left = insert(data, root->left);
        }
        else if (data > root->data)
        {
            root->right = insert(data, root->right);
        }
        return root;
    }

    Node *search(Node *root, int data)
    {
        if (root == nullptr)
        {
            cout << "Tree is empty" << endl;
            return NULL;
        }
        if (data < root->data)
        {
            return search(root->left, data); // search in left subtree
        }
        if (data > root->data)
        {
            return search(root->right, data); // search in right subtree
        }
        else
        {
            return root; // data found
        }
    }

    // Maximum element in BST
    Node *max(Node *root)
    {
        if (root == nullptr)
        {
            return NULL;
        }
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root;
    }

    // Minimum element in BST
    Node *min(Node *root)
    {
        if (root == nullptr)
        {
            return NULL;
        }
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root;
    }

    Node *findPredecessor(Node *root)
    {
        if (root->left)
        {
            // Predecessor is the rightmost node in the left subtree
            return max(root->left);
        }
        return nullptr;
    }

    Node *findSuccessor(Node *root)
    {
        if (root->right)
        {
            // Successor is the leftmost node in the right subtree
            return min(root->right);
        }
        return nullptr;
    }

    Node *delNode(Node *root, int data)
    {
        if (root == nullptr)
            return root;

        // Find the node to be deleted
        if (data < root->data)
        {
            root->left = delNode(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = delNode(root->right, data);
        }
        // Node to be deleted is found
        else
        {
            // Node with only right child or no child
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            // Node with only left child
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children
            Node *success = findSuccessor(root);

            // Replace root's data with successor's data
            root->data = success->data;

            // Delete the successor node
            root->right = delNode(root->right, success->data);
        }
        return root;
    }
};

// Function to perform in-order traversal of the BST
void inOrderTraversal(Node *root)
{
    if (root)
    {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main()
{
    // Initialize the root and insert nodes
    Node *root = new Node(50);
    root = root->insert(30, root);
    root = root->insert(70, root);
    root = root->insert(20, root);
    root = root->insert(40, root);
    root = root->insert(60, root);
    root = root->insert(80, root);

    cout << "In-order traversal of the BST: ";
    inOrderTraversal(root);
    cout << endl;

    // Searching for a node
    int searchValue = 60;
    Node *searchNode = root->search(root, searchValue);
    if (searchNode)
    {
        cout << "Node with value " << searchValue << " found." << endl;
    }
    else
    {
        cout << "Node with value " << searchValue << " not found." << endl;
    }

    // Finding the minimum and maximum elements
    Node *minNode = root->min(root);
    Node *maxNode = root->max(root);
    cout << "Minimum element: " << (minNode ? minNode->data : -1) << endl;
    cout << "Maximum element: " << (maxNode ? maxNode->data : -1) << endl;

    // Finding predecessor and successor
    Node *predecessor = root->findPredecessor(root);
    Node *successor = root->findSuccessor(root);
    cout << "Predecessor of root (50): " << (predecessor ? predecessor->data : -1) << endl;
    cout << "Successor of root (50): " << (successor ? successor->data : -1) << endl;

    // Deleting a node
    int deleteValue = 70;
    root = root->delNode(root, deleteValue);
    cout << "In-order traversal after deleting " << deleteValue << ": ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
