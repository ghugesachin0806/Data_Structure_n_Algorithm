// https://practice.geeksforgeeks.org/problems/burning-tree/1

#include <bits/stdc++.h>
using namespace std;

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
    void parent_node(Node *root, map<Node *, Node *> &mt)
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left)
            {
                q.push(temp->left);
                mt[temp->left] = temp;
            }

            if (temp->right)
            {
                q.push(temp->right);
                mt[temp->right] = temp;
            }
        }
    }

    Node *target_Node(Node *root, int element)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->data == element)
            return root;

        Node *temp1 = target_Node(root->left, element);
        Node *temp2 = target_Node(root->right, element);

        if (temp1)
            return temp1;
        else
            return temp2;
    }

    int minTime(Node *root, int target)
    {
        // Your code goes here
        map<Node *, Node *> mt;
        mt[root] = NULL;
        parent_node(root, mt);
        Node *curr = target_Node(root, target);

        queue<Node *> qt;
        qt.push(curr);

        map<Node *, bool> check;
        check[curr] = true;
        check[NULL] = true;

        int time = 0;

        while (!qt.empty())
        {
            queue<Node *> pt;
            while (!qt.empty())
            {
                Node *temp = qt.front();
                check[temp] = true;
                qt.pop();

                if (temp->left)
                {
                    if (!check[temp->left])
                        pt.push(temp->left);
                }

                if (temp->right)
                {
                    if (!check[temp->right])
                        pt.push(temp->right);
                }

                if (!check[mt[temp]])
                {
                    pt.push(mt[temp]);
                }
            }
            while (!pt.empty())
            {
                qt.push(pt.front());
                pt.pop();
            }

            if (!qt.empty())
                time++;
        }

        return time;
    }
};

// Time Complexity ------->O(NlogN)
// Space Complexity ------>O(N)