// https://www.codingninjas.com/codestudio/problems/h_920474?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h>
using namespace std;

// 1. construct two Inorder vectors for two bsts.
// 2. merge two Inorder bsts into one final Inorder.
// 3. construct single bst from that final Inorder.

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
void BST_2_Iorder(TreeNode<int> *root, vector<TreeNode<int> *> &vect)
{
    if (root == NULL)
        return;

    BST_2_Iorder(root->left, vect);
    vect.push_back(root);
    BST_2_Iorder(root->right, vect);
}

void merge_vect(vector<TreeNode<int> *> &vect1, vector<TreeNode<int> *> &vect2, vector<TreeNode<int> *> &vect)
{
    int temp1 = 0;
    int temp2 = 0;

    while (temp1 != vect1.size() && temp2 != vect2.size())
    {
        if (vect1[temp1]->data > vect2[temp2]->data)
        {
            vect.push_back(vect2[temp2]);
            temp2++;
        }
        else
        {
            vect.push_back(vect1[temp1]);
            temp1++;
        }
    }

    if (temp1 == vect1.size())
    {
        while (temp2 != vect2.size())
        {
            vect.push_back(vect2[temp2]);
            temp2++;
        }
    }
    else
    {
        while (temp1 != vect1.size())
        {
            vect.push_back(vect1[temp1]);
            temp1++;
        }
    }
}

TreeNode<int> *Inor_2_BST(vector<TreeNode<int> *> &vect, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = start + end - (start + end) / 2;

    vect[mid]->left = Inor_2_BST(vect, start, mid - 1);
    vect[mid]->right = Inor_2_BST(vect, mid + 1, end);

    return vect[mid];
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // Write your code here.
    vector<TreeNode<int> *> Inor1;
    vector<TreeNode<int> *> Inor2;
    vector<TreeNode<int> *> vect;

    BST_2_Iorder(root1, Inor1);
    BST_2_Iorder(root2, Inor2);

    merge_vect(Inor1, Inor2, vect);

    int start = 0;
    int end = vect.size() - 1;

    return Inor_2_BST(vect, start, end);
}
