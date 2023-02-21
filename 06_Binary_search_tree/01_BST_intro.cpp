#include <bits/stdc++.h>
using namespace std;

// Node of binary tree
class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Building the binary tree
void build_BST(Node *&root, int val) // passed by reference
{
    if (root == NULL)
    {
        root = new Node(val);
        return;
    }

    if (val > root->data)
    {
        build_BST(root->right, val);
    }
    else
    {
        build_BST(root->left, val);
    }
}

// taking inputs for binary tree
void takeInput(Node *&root) // passed by reference
{
    cout << "Enter the data : ";
    int val;
    cin >> val;
    while (val != -1)
    {
        build_BST(root, val);
        cin >> val;
    }
}

// level order traversal
void level_order(Node *root)
{
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
                cout << endl;
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
                qt.push(temp->left);

            if (temp->right)
                qt.push(temp->right);
        }
    }
}

int main()
{
    Node *root = NULL;
    takeInput(root);

    cout << "Inorder Traversal : " << endl;
    level_order(root);
    cout << endl;

    return 0;
}

// tree structure taken for example
// 55 44 63 40 45 62 76 10 41 99 57 61 58 7 -1
//

//          55
//        /    \
//       44     63
//      / \     / \
//     40  45  62   76
//    /  \     /     \
//   10  41   57       99
//  /         \
// 7           61
//            /
//           58

// Enter the data : 55 44 63 40 45 62 76 10 41 99 57 61 58 7 -1
// Inorder Traversal :
// 55
// 44 63
// 40 45 62 76
// 10 41 57 99
// 7 61
// 58