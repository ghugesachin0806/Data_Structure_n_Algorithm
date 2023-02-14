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

// Creating a binary Tree
Node *buildTree(Node *root)
{
    int data;
    cout << "Current Node data : ";
    cin >> data;

    // assign Node to pointer
    root = new Node(data);

    if (data == -1)
        return NULL;

    // Calling Left Child Node
    cout << "Enter data for inserting in left of : " << data << endl;
    root->left = buildTree(root->left);

    // Calling Right Child Node
    cout << "Enter data for inserting in right of : " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// inorder_traversal -----> L - N - R
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// preorder_traversal -----> N - L - R
void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// postorder_traversal -----> L - R - N
void postorder(Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


int main()
{
    // create root pointer
    Node *root = NULL;

    // Create a tree
    root = buildTree(root);

    // inorder_traversal
    cout << "\nInorder traversal : ";
    inorder(root);

    // preorder_traversal
    cout<<"\nPreorder traversal : ";
    preorder(root);

    // postorder_traversal
    cout<<"\nPostorder traversal : ";
    postorder(root);

    return 0;
}

// 1. tree structure taken for example
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

//           1
//        /     \
//       3        5
//      / \      / 
//     7   11   17  

// ------------> output
// Inorder traversal : 7 3 11 1 17 5
// Preorder traversal : 1 3 7 11 5 17
// Postorder traversal : 7 11 3 17 5 1

// 2. tree structure taken for example
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
// Inorder traversal : 12 10 22 44 6 55 3 11 8 9 33 7 20
// Preorder traversal : 55 44 22 10 12 6 33 9 3 8 11 7 20 
// Postorder traversal : 12 10 22 6 44 11 8 3 9 20 7 33 55