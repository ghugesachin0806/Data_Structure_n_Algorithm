// https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to delete a node from BST.
Node *deleteNode(Node *root, int key)
{
    // your code goes here
    if (root == NULL)
        return NULL;

    if (root->data == key)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // both child
        if (root->left != NULL && root->right != NULL)
        {
            Node *temp1 = root->left;
            Node *temp2 = root->right;
            Node *temp3 = root->left;

            while (temp1->right)
            {
                temp1 = temp1->right;
            }

            temp1->right = temp2;
            delete root;

            return temp3;
        }

        // left child
        if (root->left)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if (root->right)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
    }

    if (root->data > key)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, key);
        return root;
    }
}