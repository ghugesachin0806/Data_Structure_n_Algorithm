// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

// using stack and queue

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
//  Structure of the node of the binary tree is as
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        vector<int> vect;
        if (root == NULL)
            return vect;

        stack<Node *> st;
        queue<Node *> q;
        st.push(root);
        bool flag = true;

        while (!st.empty())
        {
            Node *temp = st.top();
            st.pop();

            vect.push_back(temp->data);

            if (flag == false)
            {
                if (temp->right)
                    q.push(temp->right);

                if (temp->left)
                    q.push(temp->left);
            }

            if (flag == true)
            {
                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }

            if (st.empty())
            {
                flag = !flag;

                while (!q.empty())
                {
                    st.push(q.front());
                    q.pop();
                }
            }
        }
        return vect;
        // Code here
    }
};
