// https://www.codingninjas.com/codestudio/problem-details/interleave-the-first-half-of-the-queue-with-the-second-half_1169450

// provided queue is even

#include <bits/stdc++.h>
using namespace std;

void solve(queue<int> &qt)
{
    int cnt = 0;
    queue<int> temp = qt;
    stack<int> st;
    while (!qt.empty())
    {
        st.push(qt.front());
        qt.pop();
        cnt++;
    }
    int temp_cnt = cnt / 2;
    while (!st.empty())
    {
        qt.push(st.top());
        st.pop();
    }
    while (!qt.empty())
    {
        st.push(qt.front());
        qt.pop();
    }
    while (temp_cnt--)
    {
        qt.push(st.top());
        st.pop();
    }
    temp_cnt = cnt / 2;
    while (temp_cnt--)
    {
        qt.push(qt.front());
        qt.push(st.top());
        st.pop();
        qt.pop();
    }
}
int main()
{
    int n;
    cin >> n;
    queue<int> qt;
    for (int i = 0; i < n; i++)
    {
        qt.push(i + 1);
    }
    solve(qt);

    cout << "Modified queue : ";
    for (int i = 0; i < n; i++)
    {
        cout << qt.front() << " ";
        qt.pop();
    }
    return 0;
}

// -> 6
// Modified queue : 1 4 2 5 3 6