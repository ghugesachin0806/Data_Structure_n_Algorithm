// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

// A binary tree node
struct Node
{
    int data;
    Node *left, *right;
};

vector<int> diagonal(Node *root)
{
    // your code here
    vector<int> vect;

    if (root == NULL)
        return vect;

    queue<Node *> qt;
    qt.push(root);
    qt.push(NULL);

    while (!qt.empty())
    {
        Node *temp = qt.front();
        qt.pop();

        if (temp == NULL)
        {
            if (qt.empty())
            {
                return vect;
            }

            qt.push(NULL);
        }
        else
        {
            while (temp)
            {
                vect.push_back(temp->data);
                if (temp->left)
                    qt.push(temp->left);

                temp = temp->right;
            }
        }
    }
}