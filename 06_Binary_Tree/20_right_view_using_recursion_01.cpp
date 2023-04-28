// using recursion

// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
#include <bits/stdc++.h>
using namespace std;

// A binary tree node

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

void recursive(Node *root, map<int, vector<int>> &mt, int cnt)
{
    if (root == NULL)
        return;

    mt[cnt].push_back(root->data);
    recursive(root->right, mt, cnt + 1);
    recursive(root->left, mt, cnt + 1);
}
// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> vect;
    map<int, vector<int>> mt;
    int cnt = 0;
    recursive(root, mt, cnt);

    for (auto key : mt)
    {
        vect.push_back(key.second[0]);
    }

    return vect;
}