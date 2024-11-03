// 23k-0832
// shahmeer Irfan
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to check if two trees are identical
bool areIdentical(TreeNode *t1, TreeNode *t2)
{
    if (!t1 && !t2)
        return true; // Both are NULL
    if (!t1 || !t2)
        return false; // One is NULL, the other is not
    if (t1->val != t2->val)
        return false; // Node values do not match

    // Recursively check the left and right subtrees
    return areIdentical(t1->left, t2->left) && areIdentical(t1->right, t2->right);
}

// Function to check if T2 is a subtree of T1
bool isSubtree(TreeNode *T1, TreeNode *T2)
{
    if (!T2)
        return true; // An empty tree is always a subtree
    if (!T1)
        return false; // If T1 is empty and T2 is not, T2 cannot be a subtree

    // Check if the trees rooted at current nodes are identical
    if (areIdentical(T1, T2))
        return true;

    // Recursively check the left and right subtrees of T1
    return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
}

int main()
{
    // Constructing tree T1
    TreeNode *T1 = new TreeNode(1);
    T1->left = new TreeNode(2);
    T1->right = new TreeNode(3);
    T1->left->left = new TreeNode(4);
    T1->left->right = new TreeNode(5);
    T1->right->right = new TreeNode(6);

    // Constructing tree T2
    TreeNode *T2 = new TreeNode(2);
    T2->left = new TreeNode(4);
    T2->right = new TreeNode(5);

    if (isSubtree(T1, T2))
    {
        cout << "T2 is a subtree of T1." << std::endl;
    }
    else
    {
        cout << "T2 is not a subtree of T1." << std::endl;
    }

    return 0;
}
