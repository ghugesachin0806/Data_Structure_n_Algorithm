// https://www.codingninjas.com/codestudio/problems/count-leaf-nodes_893055?source=youtube&campaign=LoveBabbar_Codestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudio

#include <bits/stdc++.h>
using namespace std;

template <typename T>

/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };

***********************************************************/

int inorder(BinaryTreeNode<int> *root, int cnt)
{
    if (root == NULL)
    {
        return cnt;
    }

    cnt = inorder(root->left, cnt);
    cnt = inorder(root->right, cnt);

    if (root->left == NULL && root->right == NULL)
    {
        return cnt + 1;
    }

    return cnt;
}

int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    // Write your code here.

    int cnt = 0;
    cnt = inorder(root, cnt);

    return cnt;
};
