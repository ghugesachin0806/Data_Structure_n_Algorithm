#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Stack if LIFO type operation
    stack<int> st; // Here any datatype like int, float , string can be used
    st.push(90);
    st.push(78);
    st.push(45);
    st.push(10);
    st.push(23);

    while (!st.empty())
    {
        cout << st.top() << " "; // top() <- points to top element of stack
        st.pop();
    }
    cout << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Queue is FIFO type operation
    queue<string> str; // Here any datatype like int, float , string can be used
    str.push("sachin");
    str.push("rohan");
    str.push("aniket");
    str.push("raghav");
    str.push("aman");
    str.push("chaman");

    while (!str.empty())
    {
        cout << str.front() << " ";
        str.pop();
    }
}
// 23 10 45 78 90
// sachin rohan aniket raghav aman chaman