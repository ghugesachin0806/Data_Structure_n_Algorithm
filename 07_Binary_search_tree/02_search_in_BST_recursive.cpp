// https://www.codingninjas.com/codestudio/problems/search-in-bst_1402878

#include <bits/stdc++.h>
using namespace std;

// Following is the Binary Tree node structure:

template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


// Recursive solution
bool solve(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;

    else if (root->data == x)
        return true;

    else if (x > root->data)
        return solve(root->right, x);

    else
        return solve(root->left, x);
}

bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    // Write your code here.
    bool temp = solve(root, x);

    return temp;
}

// Time complexity --->O(height of tree)
// space complexity --> O(height of tree) <------ due to recursion stack