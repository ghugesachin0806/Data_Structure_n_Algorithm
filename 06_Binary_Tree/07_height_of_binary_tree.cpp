// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

// User function template for C++


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Function to find the height of a binary tree.

    int h_tree(struct Node *node, int cnt)
    {
        if (node == NULL)
        {
            return cnt;
        }

        int cnt1 = h_tree(node->left, cnt);
        int cnt2 = h_tree(node->right, cnt);

        if (cnt1 > cnt2)
            return cnt1+1;
        else
            return cnt2+1;
    }
    int height(struct Node *node)
    {
        // code here
        int cnt = 0;

        cnt = h_tree(node, cnt);

        return cnt;
    }
};


// Here we are visiting each node single time so , 
// Time complexity --> O(n)

// space taken by recursion will be in stack and max space taken is max. height of tree
// Space complexity --> O(height)