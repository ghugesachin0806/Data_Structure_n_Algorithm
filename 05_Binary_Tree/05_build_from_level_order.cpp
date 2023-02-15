#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// inorder_traversal -----> L - N - R
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Printing trees element in level order
void levelOfTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL) // level completion detected
        {
            cout << endl;
            if (!q.empty()) // is queue have still some elements
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// Binary tree build from level_order
Node *build_from_level_order()
{
    cout << "Enter the data for root Node : ";
    int data;
    cin >> data;
    Node *root = new Node(data);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int data1;
        cout << "left node data for node : " << temp->data << " : ";
        cin >> data1;

        if (data1 != -1)
        {
            temp->left = new Node(data1);
            q.push(temp->left);
        }

        int data2;
        cout << "right node data for node : " << temp->data << " : ";
        cin >> data2;
        if (data2 != -1)
        {
            temp->right = new Node(data2);
            q.push(temp->right);
        }
    }
    return root;
}

int main()
{
    Node *root = NULL;
    root = build_from_level_order();

    cout << "Inorder traversal : ";
    inorder(root);
    cout << endl;

    cout << "level of order trversal : " << endl;
    levelOfTraversal(root);

    return 0;
}

// 1. tree structure taken for example
// 55 44 22 10 12 -1 -1 -1 -1 6 -1 -1 33 9 3 -1 8 11 -1 -1 -1 -1 7 -1 20 -1 -1

//          55
//        /    \
//       44    33
//      / \    / \
//     22  6  9   7
//    /      /     \
//   10     3       20
//  /        \
// 12         8
//           /
//          11

// ------------> output
// Enter the data for root Node : 55
// left node data for node : 55 : 44
// right node data for node : 55 : 33
// left node data for node : 44 : 22
// right node data for node : 44 : 6
// left node data for node : 33 : 9
// right node data for node : 33 : 7
// left node data for node : 22 : 10
// right node data for node : 22 : -1
// left node data for node : 6 : -1
// right node data for node : 6 : -1
// left node data for node : 9 : 3
// right node data for node : 9 : -1
// left node data for node : 7 : -1
// right node data for node : 7 : 20
// left node data for node : 10 : 12
// right node data for node : 10 : -1
// left node data for node : 3 : -1
// right node data for node : 3 : 8
// left node data for node : 20 : -1
// right node data for node : 20 : -1
// left node data for node : 12 : -1
// right node data for node : 12 : -1
// left node data for node : 8 : 11
// right node data for node : 8 : -1
// left node data for node : 11 : -1
// right node data for node : 11 : -1

// Inorder traversal : 12 10 22 44 6 55 3 11 8 9 33 7 20

// level of order trversal :
// 55
// 44 33
// 22 6 9 7
// 10 3 20
// 12 8
// 11