#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> st;

    st.push(12);
    st.push(23);
    st.push(34);
    st.push(45);
    st.push(56);
    st.push(67);

    cout << "Size of the stack : " << st.size() << endl;
    cout << "front element of the stack : " << st.front() << endl;
    cout << "back element of the stack : " << st.back() << endl;

    st.pop();
    st.pop();

    cout << "Size of the stack : " << st.size() << endl;
    cout << "front element of the stack : " << st.front() << endl;
    cout << "back element of the stack : " << st.back() << endl;

    return 0;
}

// Size of the stack : 6
// front element of the stack : 12
// back element of the stack : 67

// Size of the stack : 4
// front element of the stack : 34
// back element of the stack : 67