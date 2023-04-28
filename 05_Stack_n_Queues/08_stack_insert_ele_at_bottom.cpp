// https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &st, int value)
{
    int temp = st.top();
    st.pop();

    // BASE CONDITION

    if (st.empty())
    {
        st.push(value);
    }
    else
        solve(st, value);

    st.push(temp);
    return;
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

    cout << "size of stack : " << st.size() << endl;

    int x;
    cout << "Insert element at bottom : ";
    cin >> x;

    solve(st, x);
    cout << "size of stack : " << st.size() << endl;

    cout << "stack elements are : ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}

// size of stack : 6
// Insert element at bottom : 88
// size of stack : 7
// stack elements are : 12 23 56 78 18 90 88