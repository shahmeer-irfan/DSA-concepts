// 23k-0832
// Shahmeer Irfan
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Global variables to store the swapped nodes
TreeNode *first = nullptr;
TreeNode *second = nullptr;

// In-order traversal to find the two swapped nodes
void inorder(TreeNode *root, TreeNode *&prev)
{
    if (!root)
        return;

    inorder(root->left, prev); // Traverse left subtree

    // Check for swapped nodes
    if (prev && root->val < prev->val)
    {
        if (!first)
        {
            first = prev; // First violation found
        }
        second = root; // Update the second node
    }
    prev = root; // Update the previous node

    inorder(root->right, prev); // Traverse right subtree
}

// Function to recover the BST
void recoverTree(TreeNode *root)
{
    // Reset global variables for each recovery
    first = nullptr;
    second = nullptr;
    TreeNode *prev = nullptr; // Local variable to keep track of the previous node

    inorder(root, prev); // Perform in-order traversal

    // Swap the values of the first and second node
    if (first && second)
    {
        swap(first->val, second->val);
    }
}

// Function to print the tree in in-order traversal
void printInOrder(TreeNode *root)
{
    if (!root)
        return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

// Function to delete the tree and free memory
void deleteTree(TreeNode *root)
{
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    // Creating a sample BST with swapped nodes
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2); // Swapped node

    cout << "In-order traversal of the original BST: ";
    printInOrder(root); // Print original BST

    recoverTree(root); // Recover the BST

    cout << "\nIn-order traversal of the recovered BST: ";
    printInOrder(root); // Print recovered BST
    cout << endl;

    // Clean up the allocated memory
    deleteTree(root);

    return 0;
}
