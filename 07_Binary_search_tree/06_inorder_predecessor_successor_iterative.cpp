// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
};

void predecessor(Node *root, Node *&pre, int key)
{
    while (root != NULL)
    {
        if (root->key < key)
        {
            pre = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
}

void successor(Node *root, Node *&suc, int key)
{
    while (root != NULL)
    {
        if (root->key > key)
        {
            suc = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    // Your code goes her
    predecessor(root, pre, key);
    successor(root, suc, key);
}