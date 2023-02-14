
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

// Printing elements in reverse level order Traversal
void reverseLevelOrderTraversal(Node *root)
{
    queue<Node *> qt;
    stack<Node *> st;

    qt.push(root);
    qt.push(NULL);
    st.push(NULL);  // <---- Attention here

    while (!qt.empty())
    {
        Node *temp = qt.front();
        qt.pop();
        st.push(temp);

        if (temp == NULL)
        {
            if (!qt.empty())
            {
                qt.push(NULL);
            }
        }
        else
        {
            if (temp->left)
            {
                qt.push(temp->left);
            }
            if (temp->right)
            {
                qt.push(temp->right);
            }
        }
    }

    stack<Node *> t1;
    st.pop(); // poping the first 'NULL' element

    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();
        if (temp == NULL)
        {
            while (!t1.empty())
            {
                cout << t1.top()->data << " ";
                t1.pop();
            }
            cout << endl;
        }
        else
        {
            t1.push(temp);
        }
    }
}

int main()
{
    // create root pointer
    Node *root = NULL;

    // Create a tree
    root = buildTree(root);

    // Printing elements of tree in reversal level order
    reverseLevelOrderTraversal(root);

    return 0;
}

// tree structure taken for example
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

// 11 
// 12 8
// 10 3 20
// 22 6 9 7
// 44 33
// 55