// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

//  A binary tree Node

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    void leaf_node(Node *root, vector<int> &vect)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->left == NULL && root->right == NULL)
        {
            vect.push_back(root->data);
            return;
        }

        leaf_node(root->left, vect);
        leaf_node(root->right, vect);
    }
    void right_node(Node *root, vector<int> &vect)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
            return;

        if (root->right)
            right_node(root->right, vect);
        else if (root->left)
            right_node(root->left, vect);

        vect.push_back(root->data);
    }
    vector<int> boundary(Node *root)
    {
        vector<int> vect;
        if (root == NULL)
            return vect;

        if (root->left == NULL && root->right == NULL)
        {
            vect.push_back(root->data);
            return vect;
        }

        Node *temp = root;
        vect.push_back(temp->data);
        if (temp->left)
        {
            temp = temp->left;
            while (temp)
            {
                vect.push_back(temp->data);

                if (temp->left)
                    temp = temp->left;
                else if (temp->right)
                    temp = temp->right;

                if (temp->right == NULL && temp->left == NULL)
                    break;
            }
        }

        leaf_node(root, vect);

        if (root->right)
            right_node(root->right, vect);

        return vect;
        // Your code here
    }
};