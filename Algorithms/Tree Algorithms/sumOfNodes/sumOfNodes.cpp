#include <iostream>
#include <queue>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

int sumNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return sumNodes(root->left) + sumNodes(root->right) + root->data;
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    /*
       1
      / \
     2   3
    */

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    /*
               1
             /   \
            2     3
           / \   / \
          4   5 6   7
    */

    std::cout << sumNodes(root);

    return 0;
}