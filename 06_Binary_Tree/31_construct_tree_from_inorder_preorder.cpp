// https://practice.geeksforgeeks.org/problems/construct-tree-1/1

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
    int find(int element, int in[], int n, int start, int end)
    {
        for (int i = start; i <= end; i++)
        {
            if (element == in[i])
                return i;
        }

        return -1;
    }

    Node *solve(int in[], int pre[], int n, int &pre_ind, int start, int end)
    {
        if (pre_ind >= n || start > end)
        {
            return NULL;
        }

        int element = pre[pre_ind];
        int position = find(element, in, n, start, end);
        Node *temp = new Node(element);
        pre_ind++;

        temp->left = solve(in, pre, n, pre_ind, start, position - 1);
        temp->right = solve(in, pre, n, pre_ind, position + 1, end);

        return temp;
    }

    Node *buildTree(int in[], int pre[], int n)
    {
        // Code here
        int pre_index = 0;
        Node *temp = solve(in, pre, n, pre_index, 0, n - 1);

        return temp;
    }
};