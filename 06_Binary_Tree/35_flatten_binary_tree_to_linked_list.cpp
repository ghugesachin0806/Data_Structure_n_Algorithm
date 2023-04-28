// https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

/* utility that allocates a new Node
   with the given key  */
Node *newNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}

class Solution
{
public:
    void flatten(Node *root)
    {
        // code here
        Node *curr = root;

        while (curr)
        {
            if (curr->left)
            {
                Node *temp = curr->left;
                while (temp->right != NULL)
                {
                    temp = temp->right;
                }

                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                curr = curr->right;
            }
            else
            {
                curr = curr->right;
            }
        }
    }
};