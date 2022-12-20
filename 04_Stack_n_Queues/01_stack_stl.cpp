#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Creation of stack
    stack<int> st;

    // Push operation
    st.push(2);
    st.push(22);
    st.push(77);

    // top element in stack
    cout << "top element : " << st.top() << endl;
    cout << "size of stack : " << st.size() << endl;

    // pop the element
    st.pop();
    cout << "top element : " << st.top() << endl;
    cout << "size of stack : " << st.size() << endl;

    // stack is empty or not
    if (st.empty())
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "stack is not empty" << endl;
    }
    return 0;
}

// top element : 77
// size of stack : 3

// top element : 22
// size of stack : 2

// stack is not empty