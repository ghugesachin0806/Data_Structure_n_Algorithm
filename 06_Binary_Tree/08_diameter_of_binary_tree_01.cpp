// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
#include <bits/stdc++.h>
using namespace std;

// Tree node structure  used in the program

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

class Solution
{
public:
    // Function to return the diameter of a Binary Tree.
    int height(Node *root)
    {
        if(root==NULL)
        {
            return 0;
        }

        int cnt1 = height(root->left);
        int cnt2 = height(root->right);

        return max(cnt1,cnt2)+1;
    }

    int diameter(Node *root)
    {
        if(root==NULL)
        {
            return 0;
        }

        int cnt1= diameter(root->left);
        int cnt2 = diameter(root->right);
        int cnt3 = height(root->left)+height(root->right)+1;

        return max(cnt1 ,max(cnt2,cnt3));
        // Your code here
    }
};

// Here due to height function call each time we get total time complexity ---> O(N2)