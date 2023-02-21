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

// Iterative solution

bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    // Write your code here.
    BinaryTreeNode<int> *temp = root;

    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return true;
        }
        else if (x > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    return false;
}
