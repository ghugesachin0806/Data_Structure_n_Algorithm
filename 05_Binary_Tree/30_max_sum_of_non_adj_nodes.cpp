// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

#include <bits/stdc++.h>
using namespace std;

// Node Structure

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // Function to return the maximum sum of non-adjacent nodes.
    pair<int, int> solve(Node *root)
    {
        if (root == NULL)
        {
            pair<int, int> pt = make_pair(0, 0);
            return pt;
        }

        pair<int, int> temp1 = solve(root->left);
        pair<int, int> temp2 = solve(root->right);

        pair<int, int> temp3;

        temp3.first = root->data + temp1.second + temp2.second;
        temp3.second = max(temp1.first, temp1.second) + max(temp2.first, temp2.second);

        return temp3;
    }

    int getMaxSum(Node *root)
    {
        // Add your code here
        pair<int, int> pt = solve(root);

        return max(pt.first, pt.second);
    }
};