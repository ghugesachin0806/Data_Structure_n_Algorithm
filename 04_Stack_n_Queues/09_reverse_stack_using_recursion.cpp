// https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> &st, int value)
{
    int temp = st.top();
    st.pop();

    if (st.empty())
    {
        st.push(value);
    }
    else
    {
        insert_at_bottom(st, value);
    }
    st.push(temp);
}

void solve(stack<int> &st)
{
    int value = st.top();
    st.pop();
    if (st.empty())
    {
        st.push(value);
        return;
    }
    solve(st);
    insert_at_bottom(st, value);
}

int main()
{
    stack<int> st;
    st.push(90);
    st.push(18);
    st.push(78);
    st.push(56);
    st.push(23);
    st.push(12);
    st.push(88);

    cout << "stack elements are : ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    st.push(90);
    st.push(18);
    st.push(78);
    st.push(56);
    st.push(23);
    st.push(12);
    st.push(88);

    solve(st);

    cout << "stack elements are : ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}

// stack elements are : 88 12 23 56 78 18 90

// stack elements are : 90 18 78 56 23 12 88