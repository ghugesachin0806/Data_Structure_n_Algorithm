// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std; 

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // Your code here
        vector<int> vect;
        pair<Node *, int> pr;
        map<int, vector<int>> mt;

        queue<pair<Node *, int>> qt;

        qt.push(make_pair(root, 0));

        while (!qt.empty())
        {
            pair<Node *, int> temp = qt.front();
            qt.pop();
            mt[temp.second].push_back(temp.first->data);

            if (temp.first->left)
            {
                pair<Node *, int> t1 = make_pair(temp.first->left, temp.second - 1);
                qt.push(t1);
            }
            if (temp.first->right)
            {
                pair<Node *, int> t2 = make_pair(temp.first->right, temp.second + 1);
                qt.push(t2);
            }
        }

        for (auto k1 : mt)
        {
            auto it = k1.second.end();
            it--;
            vect.push_back(*it);
        }

        return vect;
    }
};