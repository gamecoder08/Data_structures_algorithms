#include <iostream>

class BtreeNode
{
public:
    int *keys;
    int t;
    BtreeNode **C;
    int n;
    bool leaf;

    BtreeNode(int _t, bool _leaf)
    {
        t = _t;
        leaf = _leaf;
        keys = new int[2 * t - 1];
        C = new BtreeNode *[2 * t];
        n = 0;
    }

    void splitChild(BtreeNode *y, int i)
    {
        BtreeNode *z = new BtreeNode(y->t, y->leaf);
        z->n = y->t - 1;

        for (int j = 0; j < y->t - 1; j++)
        {
            z->keys[j] = y->keys[j + t];
        }
        if (!y->leaf)
        {
            for (int j = 0; j < y->t; j++)
            {
                z->C[j] = y->C[j + t];
            }
        }

        y->n = t - 1;

        for (int j = n; j >= i; j--)
        {
            C[j + 1] = C[j];
        }
        C[i + 1] = z;

        for (int j = n - 1; j >= i; j--)
        {
            keys[j + 1] = keys[j];
        }
        keys[i] = y->keys[t - 1];
        n++;
    }

    void insertNonFull(int k)
    {
        int i = n - 1;

        if (leaf)
        {
            while (i >= 0 && keys[i] > k)
            {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = k;
            n++;
        }
        else
        {
            while (i >= 0 && keys[i] > k)
            {
                i--;
            }
            if (C[i + 1]->n == 2 * t - 1)
            {
                splitChild(C[i + 1], i + 1);
                if (keys[i + 1] < k)
                {
                    i++;
                }
            }
            C[i + 1]->insertNonFull(k);
        }
    }

    void traverse()
    {
        int i;
        for (i = 0; i < n; i++)
        {
            if (!leaf)
            {
                C[i]->traverse();
            }
            std::cout << keys[i] << " ";
        }
        if (!leaf)
        {
            C[i]->traverse();
        }
    }
};

class Btree
{
public:
    BtreeNode *root;
    int t;

    Btree(int _t)
    {
        root = nullptr;
        t = _t;
    }

    void insert(int k)
    {
        if (root == nullptr)
        {
            root = new BtreeNode(t, true);
            root->keys[0] = k;
            root->n = 1;
        }
        else
        {
            if (root->n == 2 * t - 1)
            {
                BtreeNode *s = new BtreeNode(t, false);
                s->C[0] = root;
                s->splitChild(root, 0);

                int i = 0;
                if (s->keys[0] < k)
                {
                    i++;
                }
                s->C[i]->insertNonFull(k);
                root = s;
            }
            else
            {
                root->insertNonFull(k);
            }
        }
    }
};

int main()
{
    Btree t(3);
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    std::cout << "Traversal of the constructed B-Tree is: ";
    t.root->traverse();

    return 0;
}