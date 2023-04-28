// https://practice.geeksforgeeks.org/problems/k-sum-paths/1

// vector always pass by value , not by reference

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
    // vector always pass by value , not by reference
    void solve(Node *root, vector<int> vect, int k, int &add)
    {
        if (root == NULL)
        {
            return;
        }

        vect.push_back(root->data);

        solve(root->left, vect, k, add);
        solve(root->right, vect, k, add);

        int sum = 0;
        for (int i = vect.size() - 1; i >= 0; i--)
        {
            sum = sum + vect[i];
            if (sum == k)
                add++;
        }
    }

    int sumK(Node *root, int k)
    {
        // code here
        int add = 0;
        vector<int> vect;
        solve(root, vect, k, add);

        return add;
    }
};