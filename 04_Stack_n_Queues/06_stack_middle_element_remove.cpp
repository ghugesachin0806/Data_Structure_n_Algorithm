// https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &st, int size, int cnt)
{
    int top_ele = st.top();
    st.pop();
    // Base condition
    if (cnt == (size) / 2)
    {
        cout << "middle element :" << top_ele << endl;
        return;
    }

    // recursive call
    solve(st, size, cnt + 1);
    st.push(top_ele);
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
    int cnt = 0;

    solve(st, st.size(), cnt);
    cout << "stack top : " << st.top() << endl;

    solve(st, st.size(), cnt);
    cout << "stack top : " << st.top() << endl;

    solve(st, st.size(), cnt);
    cout << "stack top : " << st.top() << endl;

    return 0;
}

// middle element :78
// stack top : 12

// middle element :56
// stack top : 12

// middle element :18
// stack top : 12