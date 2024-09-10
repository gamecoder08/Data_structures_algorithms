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

int searchPos(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

Node *buildTREE(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }
    int curr = preorder[idx];
    idx++;

    Node *node = new Node(curr);

    if (start == end)
    {
        return node;
    }
    int pos = searchPos(inorder, start, end, curr);
    node->left = buildTREE(preorder, inorder, start, pos - 1);
    node->right = buildTREE(preorder, inorder, pos + 1, end);

    return node;
}

void checkInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    checkInorder(root->left);
    std::cout << root->data << " ";
    checkInorder(root->right);
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    Node *root = buildTREE(preorder, inorder, 0, 4);
    checkInorder(root);

    return 0;
}