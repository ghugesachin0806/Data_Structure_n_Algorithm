// https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

void sort(stack<int> &st, int value)
{
    if (st.empty())
    {
        st.push(value);
        return;
    }
    if (st.top() < value)
    {
        st.push(value);
        return;
    }

    int temp = st.top();
    st.pop();
    sort(st, value);
    st.push(temp);
}

void solve(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int value = st.top();
    st.pop();

    solve(st);

    sort(st, value);
}

int main()
{
    stack<int> st;
    st.push(23);
    st.push(90);
    st.push(118);
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
    cout << endl;

    return 0;
}

// stack elements are : 118 90 88 78 56 23 23 12