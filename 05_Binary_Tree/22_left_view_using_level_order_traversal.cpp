// Using level order traversal

// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

// A binary tree node

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> vect;
    queue<Node *> qt;

    qt.push(root);
    qt.push(NULL);

    while (!qt.empty())
    {
        Node *temp = qt.front();
        qt.pop();

        if (temp == NULL)
        {
            if (!qt.empty())
            {
                qt.push(NULL);
            }
            continue;
        }
        else
        {
            if (qt.front() == NULL)
                vect.push_back(temp->data);

            if (temp->right)
                qt.push(temp->right);

            if (temp->left)
                qt.push(temp->left);
        }
    }

    return vect;
}