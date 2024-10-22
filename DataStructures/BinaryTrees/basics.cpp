#include <iostream>
#include<queue>

using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;
    friend Node *buildTree(Node *root);
    friend void levelOrderTraversel(Node *root);
    friend void inOrder(Node *root);
    friend void preOrder(Node *root);
    friend void postOrder(Node *root);

    public:
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout<<"Enter value of root node: "<<endl;

    int data;
    cin>>data;
    root = new Node(data);

    if(data==-1)
    {
        return NULL;
    }
  
    cout<<"Enter left child of "<<data<<": "<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter right child of"<<data<<": "<<endl;
    root->right = buildTree(root->right);

    return root;

}

void levelOrderTraversel(Node *root)
{
    if(root==nullptr)
    {
        return;
    }
    queue<Node *> q;  //queue of Node pointers
    q.push(root);
    //q.push(NULL);

        while(!q.empty())
        {
            Node *temp = q.front();
            cout<<temp->data<<endl;
            q.pop();

            // separator logic to print in tree format
            // if(temp==NULL)
            // {
            //     cout<<endl;
            //     if(!q.empty())
            //     {
            //         q.push(NULL);
            //     }
            // }

            if(temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            }

        }
}

void inOrder(Node *root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);       // Traverse the left subtree
    cout << root->data << " "; // Visit the root
    inOrder(root->right);      // Traverse the right subtree
}

void preOrder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " "; // Visit the root
    preOrder(root->left);      // Traverse the left subtree
    preOrder(root->right);     // Traverse the right subtree
}

void postOrder(Node *root)
{
    if (root == nullptr)
        return;
    postOrder(root->left);     // Traverse the left subtree
    postOrder(root->right);    // Traverse the right subtree
    cout << root->data << " "; // Visit the root
}

int main()
{

    Node *root = NULL;
    root = buildTree(root);
    //test case input: 1 3 7 -1 -1 11 -1  5 17 -1 -1 -1  //-1 = null
    //output: 1 3 5 7 11 17
    levelOrderTraversel(root);





    return 0;
}