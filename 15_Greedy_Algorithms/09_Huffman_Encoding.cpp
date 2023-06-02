// https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class comparator
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    void preorder_traversal(Node *root, string temp, vector<string> &ans)
    {
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(temp);
            return;
        }

        if (root->left)
            preorder_traversal(root->left, temp + '0', ans);
        if (root->right)
            preorder_traversal(root->right, temp + '1', ans);
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        // Code here
        priority_queue<Node *, vector<Node *>, comparator> qt; // Max_Heap for Nodes

        for (int i = 0; i < f.size(); i++)
        {
            Node *n1 = new Node(f[i]);
            qt.push(n1);
        }

        while (qt.size() > 1)
        {
            Node *temp1 = qt.top();
            qt.pop();
            Node *temp2 = qt.top();
            qt.pop();

            Node *n1 = new Node(temp1->data + temp2->data);
            n1->left = temp1;
            n1->right = temp2;
            qt.push(n1);
        }

        vector<string> ans;
        string temp = "";

        preorder_traversal(qt.top(), temp, ans);

        return ans;
    }
};