
// Here , we are using "stacks" to traverse the binary tree in iterative way in inorder, preorder, postorder

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
vector<int> inorder(Node *root)
{
    vector<int> vect;
    stack<Node *> st;
    Node *t_root = root;

    while (true)
    {
        if (t_root != NULL)
        {
            st.push(t_root);
            t_root = t_root->left;
        }
        else
        {
            if (st.empty())
                break;

            Node *temp = st.top();
            st.pop();
            vect.push_back(temp->data);
            t_root = temp->right;
        }
    }
    return vect;
}

// preorder_traversal -----> N - L - R
vector<int> preorder(Node *root)
{
    vector<int> vect;
    if (root == NULL)
        return vect;

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();
        vect.push_back(temp->data);

        // -----> Attention below, it is stack
        // Therefore , it is executed in below manner
        if (temp->right)
        {
            st.push(temp->right);
        }
        if (temp->left)
        {
            st.push(temp->left);
        }
    }
    return vect;
}

// postorder_traversal -----> L - R - N
// using two stack
vector<int> postorder1(Node *root)
{
    vector<int> vect;
    stack<Node *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        Node *temp = st1.top();
        st2.push(st1.top());
        st1.pop();

        if (temp->left)
        {
            st1.push(temp->left);
        }
        if (temp->right)
        {
            st1.push(temp->right);
        }
    }

    while (!st2.empty())
    {
        vect.push_back(st2.top()->data);
        st2.pop();
    }

    return vect;
}

// postorder_traversal -----> L - R - N
// using single stack
vector<int> postorder2(Node *root)
{
    vector<int> vect;
    stack<Node *> st;

    Node *curr = root;

    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                vect.push_back(temp->data);
                st.pop();

                while (!st.empty())
                {
                    if (temp == st.top()->right)
                    {
                        temp = st.top();
                        vect.push_back(temp->data);
                        st.pop();
                    }
                    else
                        break;
                }
            }
            else
                curr = temp;
        }
    }
    return vect;
}

int main()
{
    // create root pointer
    Node *root = NULL;

    // Create a tree
    root = buildTree(root);

    vector<int> vect1;
    vector<int> vect2;
    vector<int> vect3;
    vector<int> vect4;

    // preorder_iterative_traversal
    vect1 = preorder(root);
    cout << "\nPreorder traversal : ";
    for (int i = 0; i < vect1.size(); i++)
    {
        cout << vect1[i] << " ";
    }

    // inorder_iterative_traversal
    vect2 = inorder(root);
    cout << "\nInorder trversal : ";
    for (int i = 0; i < vect2.size(); i++)
    {
        cout << vect2[i] << " ";
    }

    // postorder_iterative_traversal
    // using two stack
    vect3 = postorder1(root);
    cout << "\nPostorder1 traversal : ";
    for (int i = 0; i < vect3.size(); i++)
    {
        cout << vect3[i] << " ";
    }

    // postorder_iterative_traversal
    // using single stack
    vect4 = postorder2(root);
    cout << "\nPostorder2 traversal : ";
    for (int i = 0; i < vect4.size(); i++)
    {
        cout << vect4[i] << " ";
    }
    cout << endl;

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
// Preorder traversal : 1 3 7 11 5 17
// Inorder trversal : 7 3 11 1 17 5
// Postorder1 traversal : 7 11 3 17 5 1
// Postorder2 traversal : 7 11 3 17 5 1

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
// Preorder traversal : 55 44 22 10 12 6 33 9 3 8 11 7 20
// Inorder trversal : 12 10 22 44 6 55 3 11 8 9 33 7 20 
// Postorder1 traversal : 12 10 22 6 44 11 8 3 9 20 7 33 55
// Postorder2 traversal : 12 10 22 6 44 11 8 3 9 20 7 33 55