#include <iostream>

class AVLNode
{
public:
    int key;
    AVLNode *left;
    AVLNode *right;
    int height;
    AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree
{
private:
    AVLNode *root;

    int height(AVLNode *N)
    {
        return N ? N->height : 0;
    }

    int getBalance(AVLNode *N)
    {
        return N ? height(N->left) - height(N->right) : 0;
    }

    AVLNode *rightRotate(AVLNode *y)
    {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x;
    }

    AVLNode *leftRotate(AVLNode *x)
    {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;

        y->left = x;
        x->right = T2;

        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return y;
    }

    AVLNode *insert(AVLNode *node, int key)
    {
        if (!node)
            return new AVLNode(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + std::max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->left->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(AVLNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
    }

public:
    AVLTree()
    {
        root = nullptr;
    }

    void insert(int key)
    {
        root = insert(root, key);
    }

    void inorder()
    {
        inorder(root);
        std::cout << std::endl;
    }
};

int main()
{
    AVLTree tree;
    tree.insert(21);
    tree.insert(8);
    tree.insert(7);
    tree.insert(20);
    tree.insert(29);
    tree.insert(25);
    tree.insert(19);
    tree.insert(30);
    tree.insert(6);
    tree.insert(13);

    tree.inorder();
    return 0;
}