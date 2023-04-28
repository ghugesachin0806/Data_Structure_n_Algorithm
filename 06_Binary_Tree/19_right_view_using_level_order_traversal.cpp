// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

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

// Should return  right view of tree
class Solution
{
public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        // Your Code here
        vector<int> vect;
        queue<Node *> qt;

        qt.push(root);
        qt.push(NULL);

        while (!qt.empty())
        {
            Node *temp = qt.front();
            qt.pop();

            if (temp == NULL)
            {
                if (!qt.empty())
                {
                    qt.push(NULL);
                }
                continue;
            }
            else
            {
                if (qt.front() == NULL)
                    vect.push_back(temp->data);

                if (temp->left)
                    qt.push(temp->left);
                if (temp->right)
                    qt.push(temp->right);
            }
        }

        return vect;
    }
};
