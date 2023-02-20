// https://practice.geeksforgeeks.org/problems/inorder-traversal/1

// Theory --->
// https://leetcode.com/problems/binary-tree-inorder-traversal/solutions/148939/CPP-Morris-Traversal/

#include <bits/stdc++.h>
using namespace std;

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

class Solution
{
public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node *root)
    {
        // Your code here
        vector<int> vect;

        if (root == NULL)
            return vect;

        Node *curr = root;

        while (curr)
        {
            if (curr->left)
            {
                Node *temp = curr->left;
                while (temp->right != NULL && temp->right != curr)
                {
                    temp = temp->right;
                }

                if (temp->right == NULL)
                {
                    temp->right = curr;
                    curr = curr->left;
                }
                else
                {
                    // coming back
                    vect.push_back(curr->data);
                    curr = curr->right;
                    temp->right = NULL;
                }
            }
            else
            {
                vect.push_back(curr->data);
                curr = curr->right;
            }
        }

        return vect;
    }
};