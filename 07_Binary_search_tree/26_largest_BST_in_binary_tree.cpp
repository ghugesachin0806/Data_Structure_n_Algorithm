// https://practice.geeksforgeeks.org/problems/largest-bst/1

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
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    class info
    {
    public:
        int maxi;
        int mini;
        bool bt;
        int ans;
    };

    info solve(Node *root)
    {
        if (root == NULL)
        {
            info temp;
            temp.ans = 0;
            temp.bt = true;
            temp.mini = INT_MAX;
            temp.maxi = INT_MIN;

            return temp;
        }
        info curr;

        info temp1 = solve(root->left);
        info temp2 = solve(root->right);

        if (root->data > temp1.maxi && root->data < temp2.mini && temp1.bt && temp2.bt)
            curr.bt = true;
        else
            curr.bt = false;

        if (curr.bt)
            curr.ans = temp1.ans + temp2.ans + 1;
        else
            curr.ans = max(temp1.ans, temp2.ans);

        curr.maxi = max(root->data, max(temp1.maxi, temp2.maxi));
        curr.mini = min(root->data, min(temp1.mini, temp2.mini));

        return curr;
    }

    int largestBst(Node *root)
    {
        // Your code here
        info temp = solve(root);

        return temp.ans;
    }
};