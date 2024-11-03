//23k-0832
//shahmeer irfan
#include <iostream>
#include <algorithm> // For std::max

using namespace std;

struct TreeNode
{
    int val; 
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int maxProfitPath(TreeNode *root)
{
    if (!root)
        return 0; // Base case: return 0 for null nodes

    // Recursively find the maximum profit in the left and right subtrees
    int leftProfit = maxProfitPath(root->left);
    int rightProfit = maxProfitPath(root->right);

    // Return the maximum profit path from this node to its children
    return root->val + max(leftProfit, rightProfit);
}

int main()
{
    // Creating a sample binary tree for demonstration
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    // Calculate the maximum profit path
    int maxProfit = maxProfitPath(root);
    cout << "Maximum profit path: " << maxProfit << endl;


    return 0;
}
