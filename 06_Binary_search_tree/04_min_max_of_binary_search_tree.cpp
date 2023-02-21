// https://practice.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    int findMax(Node *root)
    {
        // code here
        Node *temp = root;
        while (temp->right != NULL)
            temp = temp->right;

        return temp->data;
    }
    int findMin(Node *root)
    {
        // code here
        Node *temp = root;
        while (temp->left != NULL)
            temp = temp->left;

        return temp->data;
    }
};