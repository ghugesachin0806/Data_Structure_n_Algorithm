// https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

//************************************************************

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

//************************************************************/
void solve(TreeNode<int> *root, TreeNode<int> *&head)
{
    if (root == NULL)
        return;

    solve(root->right, head);

    root->right = head;

    head = root;

    solve(root->left, head);
    root->left = NULL;
}
TreeNode<int> *flatten(TreeNode<int> *root)
{
    // Write your code here
    TreeNode<int> *head = NULL;

    solve(root, head);

    return head;
}