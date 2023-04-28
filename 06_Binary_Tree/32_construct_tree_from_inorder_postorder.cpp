// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

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
        left = right = NULL;
    }
};

// Function to return a tree created from postorder and inoreder traversals.
int find(int element, int in[], int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (element == in[i])
            return i;
    }
    return -1;
}
Node *solve(int in[], int post[], int n, int start, int end, int &post_ind)
{
    if (post_ind < 0 || start > end)
    {
        return NULL;
    }

    int element = post[post_ind];
    int position = find(element, in, start, end);
    Node *temp = new Node(element);
    post_ind--;

    temp->right = solve(in, post, n, position + 1, end, post_ind);
    temp->left = solve(in, post, n, start, position - 1, post_ind);

    return temp;
}
Node *buildTree(int in[], int post[], int n)
{
    // Your code here
    int post_ind = n - 1;
    Node *temp = solve(in, post, n, 0, n - 1, post_ind);

    return temp;
}