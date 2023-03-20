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

void Inordered(TreeNode<int> *root, vector<TreeNode<int> *> &vect)
{
    if (root == NULL)
        return;

    Inordered(root->left, vect);
    vect.push_back(root);
    Inordered(root->right, vect);
}

TreeNode<int> *flatten(TreeNode<int> *root)
{
    // Write your code here
    vector<TreeNode<int> *> vect;

    Inordered(root, vect);
    TreeNode<int> *head = vect[0];

    for (int i = 0; i < vect.size() - 1; i++)
    {
        vect[i]->left = NULL;
        vect[i]->right = vect[i + 1];
    }
    vect[vect.size() - 1]->left = NULL;
    vect[vect.size() - 1]->right = NULL;

    return head;
}

// ********************************* second solution ****************************************

// void Inordered(TreeNode<int> *root,vector<int> &vect)
// {
//     if(root==NULL)
//     return;

//     Inordered(root->left,vect);
//     vect.push_back(root->data);
//     Inordered(root->right,vect);
// }

// TreeNode<int> *flatten(TreeNode<int> *root)
// {
//     // Write your code here
//     vector<int> vect;

//     Inordered(root,vect);
//     // TreeNode<int> *head = vect[0];
//     TreeNode<int>* head = new TreeNode<int>(vect[0]);
//     TreeNode<int>* curr = head;

//     for(int i=1;i<vect.size();i++)
//     {
//         curr->left=NULL;
//         TreeNode<int>* temp = new TreeNode<int>(vect[i]);
//         curr->right = temp;
//         curr = temp;
//         temp =NULL;
//     }

//     return head;
// }