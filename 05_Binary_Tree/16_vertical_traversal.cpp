// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:

    vector<int> verticalOrder(Node *root)
    {
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
            for (int i = 0; i < k1.second.size(); i++)
            {
                vect.push_back(k1.second[i]);
            }
        }

        return vect;
    }
};