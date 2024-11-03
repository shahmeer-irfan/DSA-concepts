//23k-0832
// shahmeer irfan
#include <iostream>
#include <stack>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void zigzagTraversal(TreeNode *root)
{
    if (!root)
        return;

    std::stack<TreeNode *> currentLevel; // Stack for the current level
    std::stack<TreeNode *> nextLevel;    // Stack for the next level
    bool leftToRight = true;             // Direction indicator

    currentLevel.push(root);

    while (!currentLevel.empty())
    {
        TreeNode *node = currentLevel.top();
        currentLevel.pop();

        if (node)
        {
            std::cout << node->val << " ";

            // Push children to the next level stack based on current direction
            if (leftToRight)
            {
                if (node->left)
                    nextLevel.push(node->left);
                if (node->right)
                    nextLevel.push(node->right);
            }
            else
            {
                if (node->right)
                    nextLevel.push(node->right);
                if (node->left)
                    nextLevel.push(node->left);
            }
        }

        // If current level is done, swap stacks and change direction
        if (currentLevel.empty())
        {
            leftToRight = !leftToRight;
            std::swap(currentLevel, nextLevel);
        }
    }
}

int main()
{
    // Constructing a simple binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::cout << "Zigzag Order Traversal: ";
    zigzagTraversal(root);
    std::cout << std::endl;

    return 0;
}
