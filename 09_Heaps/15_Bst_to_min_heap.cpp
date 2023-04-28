// https://www.codingninjas.com/codestudio/problems/convert-bst-to-min-heap_920498

// Convert BST into Minheap tree such that,
// All the values in left subtree should be smaller than all the values in right subtree

#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{

public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};

// *************************************************************/
void Inor(BinaryTreeNode *root, vector<int> &vect)
{
    if (root == NULL)
        return;

    Inor(root->left, vect);
    vect.push_back(root->data);
    Inor(root->right, vect);
}

void solve(BinaryTreeNode *root, vector<int> &vect, int &index)
{
    if (root == NULL)
        return;

    root->data = vect[index++];

    solve(root->left, vect, index);
    solve(root->right, vect, index);
}

BinaryTreeNode *convertBST(BinaryTreeNode *root)
{
    // Write your code here.
    vector<int> vect;
    Inor(root, vect);

    int index = 0;
    solve(root, vect, index);

    return root;
}