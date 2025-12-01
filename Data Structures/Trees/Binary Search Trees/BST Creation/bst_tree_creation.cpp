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
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);

    /*
              4
             / \
            2   6
           / \  /
          1   3 5
    */

    std::cout << "Root: " << root->data << std::endl;
    std::cout << "Left Child of Root: " << root->left->data << std::endl;
    std::cout << "Right Child of Root: " << root->right->data << std::endl;
    std::cout << "Left Child of Left Child: " << root->left->left->data << std::endl;
    std::cout << "Right Child of Left Child: " << root->left->right->data << std::endl;
    std::cout << "Left Child of Right Child: " << root->right->left ->data << std::endl;
    return 0;
}