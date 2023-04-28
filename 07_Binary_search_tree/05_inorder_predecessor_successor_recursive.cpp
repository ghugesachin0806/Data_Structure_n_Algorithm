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
    if (root == NULL)
        return;

    if (root->key < key)
    {
        pre = root;
        predecessor(root->right, pre, key);
    }
    else
    {
        predecessor(root->left, pre, key);
    }
}

void successor(Node *root, Node *&suc, int key)
{
    if (root == NULL)
    {
        return;
    }

    if (root->key > key)
    {
        suc = root;
        successor(root->left, suc, key);
    }
    else
    {
        successor(root->right, suc, key);
    }
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    // Your code goes her
    predecessor(root, pre, key);
    successor(root, suc, key);
}