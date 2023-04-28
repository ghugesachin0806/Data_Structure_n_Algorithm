// https://www.codingninjas.com/codestudio/problems/h_920474?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h>
using namespace std;

// 1. convert bst into sorted linked list
// 2. Merge 2 sorted LINKED LIST
// 3. CONVERT merged linked list into BST

template <typename T>

class TreeNode
{

public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
        {
            delete left;
        }

        if (right)
        {
            delete right;
        }
    }
};

// *************************************************************/
void BST_DLL(TreeNode<int> *root, TreeNode<int> *&head)
{
    if (root == NULL)
        return;

    BST_DLL(root->right, head);

    root->right = head;

    if (head != NULL)
        head->left = root;

    head = root;

    BST_DLL(root->left, head);
}

void Merge_DLL(TreeNode<int> *head1, TreeNode<int> *head2, TreeNode<int> *&head)
{

    if (head1->data >= head2->data)
    {
        head = head2;
        head2 = head2->right;
    }
    else
    {
        head = head1;
        head1 = head1->right;
    }

    TreeNode<int> *temp = head;

    while (head1 && head2)
    {
        if (head1->data >= head2->data)
        {
            temp->right = head2;
            head2->left = temp;
            temp = head2;
            head2 = head2->right;
        }
        else
        {
            temp->right = head1;
            head1->left = temp;
            temp = head1;
            head1 = head1->right;
        }
    }

    while (head1)
    {
        temp->right = head1;
        head1->left = temp;
        temp = head1;
        head1 = head1->right;
    }

    while (head2)
    {
        temp->right = head2;
        head2->left = temp;
        temp = head2;
        head2 = head2->right;
    }
}

int cntL(TreeNode<int> *root)
{
    int k = 0;
    while (root)
    {
        k++;
        root = root->right;
    }

    return k;
}

TreeNode<int> *DLL_BST(TreeNode<int> *root)
{
    int n = cntL(root);

    if (root == NULL || n == 0)
        return NULL;

    int mid = n - (n / 2);
    int k = 1;

    TreeNode<int> *temp = root;

    while (k != mid)
    {
        temp = temp->right;
        k++;
    }

    TreeNode<int> *prev = temp->left;
    TreeNode<int> *next = temp->right;

    if (prev)
        prev->right = NULL;
    if (next)
        next->left = NULL;

    if(prev)
    temp->left = DLL_BST(root);
    else
    temp->left =NULL;
    temp->right = DLL_BST(next);

    return temp;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // Write your code here.

    TreeNode<int> *head1 = NULL;
    TreeNode<int> *head2 = NULL;
    TreeNode<int> *head = NULL;

    BST_DLL(root1, head1);
    BST_DLL(root2, head2);

    Merge_DLL(head1, head2, head);

    return DLL_BST(head);
}

