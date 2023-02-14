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

// Height of binary tree
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);

    if (lheight > rheight)
        return lheight+1;
    else
        return rheight+1;
}

int main()
{
    // create root pointer
    Node *root = NULL;

    // Create a tree
    root = buildTree(root);

    // Printing trees of element in order

    cout << "Binary tree elements by level : " << endl;
    levelOfTraversal(root);

    cout<<"height of binary tree : "<<height(root);

    return 0;
}

// tree structure taken for example

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

//-----------> output

// Current Node data : 55
// Enter data for inserting in left of : 55
// Current Node data : 44
// Enter data for inserting in left of : 44
// Current Node data : 22
// Enter data for inserting in left of : 22
// Current Node data : 10
// Enter data for inserting in left of : 10
// Current Node data : 12
// Enter data for inserting in left of : 12
// Current Node data : -1
// Enter data for inserting in right of : 12
// Current Node data : -1
// Enter data for inserting in right of : 10
// Current Node data : -1
// Enter data for inserting in right of : 22
// Current Node data : -1
// Enter data for inserting in right of : 44
// Current Node data : 6
// Enter data for inserting in left of : 6
// Current Node data : -1
// Enter data for inserting in right of : 6
// Current Node data : -1
// Enter data for inserting in right of : 55
// Current Node data : 33
// Enter data for inserting in left of : 33
// Current Node data : 9
// Enter data for inserting in left of : 9
// Current Node data : 3
// Enter data for inserting in left of : 3
// Current Node data : -1
// Enter data for inserting in right of : 3
// Current Node data : 8
// Enter data for inserting in left of : 8
// Current Node data : 11
// Enter data for inserting in left of : 11
// Current Node data : -1
// Enter data for inserting in right of : 11
// Current Node data : -1
// Enter data for inserting in right of : 8
// Current Node data : -1
// Enter data for inserting in right of : 9
// Current Node data : -1
// Enter data for inserting in right of : 33
// Current Node data : 7
// Enter data for inserting in left of : 7
// Current Node data : -1
// Enter data for inserting in right of : 7
// Current Node data : 20
// Enter data for inserting in left of : 20
// Current Node data : -1
// Enter data for inserting in right of : 20
// Current Node data : -1

// Binary tree elements by level : 
// 55
// 44 33
// 22 6 9 7
// 10 3 20
// 12 8
// 11

// height of binary tree : 6