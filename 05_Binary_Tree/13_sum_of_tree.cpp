#include <bits/stdc++.h>
using namespace std;

//  Tree node
struct Node
{
    int data;
    Node *left, *right;
};

// Should return true if tree is Sum Tree, else false
class Solution
{
public:
    pair<int, bool> check(Node *root)
    {
        if (root == NULL)
        {
            pair<int, bool> temp = make_pair(0, true);
            return temp;
        }

        if (root->left == NULL && root->right == NULL)
        {
            pair<int, bool> temp = make_pair(root->data, true);
            return temp;
        }

        pair<int, bool> b1 = check(root->left);
        pair<int, bool> b2 = check(root->right);

        pair<int, bool> curr = make_pair(0, false);

        int val = b1.first + b2.first + root->data;

        bool bt = (root->data == (b1.first + b2.first));

        pair<int, bool> t1 = make_pair(val, true);

        if (b1.second && b2.second && bt)
            return t1;
        else
            return curr;
    }

    bool isSumTree(Node *root)
    {
        pair<int, bool> pt = check(root);
        return pt.second;
    }
};

// Time complexity ----> O(N)