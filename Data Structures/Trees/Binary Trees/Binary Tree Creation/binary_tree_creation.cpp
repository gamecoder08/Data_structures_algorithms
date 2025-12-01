#include <iostream>

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

    /*
              1
             / \
            2   3
           / \
          4   5
    */

    // Print the tree structure
    std::cout << "Root: " << root->data << std::endl;
    std::cout << "Left Child of Root: " << root->left->data << std::endl;
    std::cout << "Right Child of Root: " << root->right->data << std::endl;
    std::cout << "Left Child of Left Child: " << root->left->left->data << std::endl;
    std::cout << "Right Child of Left Child: " << root->left->right->data << std::endl;

    return 0;
}