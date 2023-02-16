
// In c++ , if there are multiple conditions inside 'if block' then compiler will check them from left to right manner
// if block check the statements in LEFT to Right for multiple statements in 'if block'

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

int main()
{
    stack<Node *> st;
    Node *temp = new Node(67);
    st.push(temp);
    st.pop();

    // statement1 = st.empty() ----------------> true statement
    // statement2 = st.top()->right == temp ---> runtime error statement
    // In below code, statement1 is true , so whole block will be true because of 'OR'(||) between two statements ,
    // so compiler will not check statement2 and execute 'if statement' block.
    if (st.empty() || st.top()->right == temp)
    {
        cout << "statement 1 : " << endl;
        st.pop();
    }

    cout << "statement 3 : " << endl;

    // statement1 = st.top()->right == temp ---> runtime error statement
    // statement2 = st.empty() ----------------> true statement
    // Here statement1 is runtime error.so, program will be abruptly stops , no further executed
    if (st.top()->right == temp || st.empty())
    {
        cout << "statement 4 : " << endl;
        st.pop();
    }

    cout << "statement 5 : " << endl;
}

// statement 1 :
// statement 3 :