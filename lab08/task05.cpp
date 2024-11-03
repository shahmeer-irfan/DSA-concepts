//23k-0832
//shahmeer irfan
#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to convert a sorted array to a balanced BST
TreeNode *sortedArrayToBST(int arr[], int left, int right)
{
    if (left > right)
    {
        return nullptr; // Base case: no elements to construct the tree
    }

    // Find the middle element
    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(arr[mid]); // Create a new TreeNode with the middle element

    // Recursively construct the left and right subtrees
    root->left = sortedArrayToBST(arr, left, mid - 1);   // Left half
    root->right = sortedArrayToBST(arr, mid + 1, right); // Right half

    return root; // Return the constructed BST
}

// Function to print the tree in pre-order traversal
void preOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    std::cout << root->val << " "; // Visit the root
    preOrder(root->left);          // Traverse left subtree
    preOrder(root->right);         // Traverse right subtree
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};    // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    TreeNode *root = sortedArrayToBST(arr, 0, n - 1); // Convert array to BST

    std::cout << "Pre-order traversal of the constructed BST: ";
    preOrder(root); // Print the pre-order traversal of the BST

    return 0;
}
