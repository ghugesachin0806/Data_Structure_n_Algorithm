// https://practice.geeksforgeeks.org/problems/queue-reversal/1

#include <bits/stdc++.h>
using namespace std;

////////////////// solved by stack //////////////////////////////////////////////////
void solution_using_stack(queue<int> qt)
{
    stack<int> st;

    while (!qt.empty())
    {
        st.push(qt.front());
        qt.pop();
    }

    while (!st.empty())
    {
        qt.push(st.top());
        st.pop();
    }

    cout << "reversed queue : ";
    while (!qt.empty())
    {
        cout << qt.front() << " ";
        qt.pop();
    }
    cout << endl;
}

//////////////////////////////////// solved using recursion ////////////////////////////
void solution_using_recursion(queue<int> &qt)
{
    int temp = qt.front();
    qt.pop();

    if (qt.empty())
    {
        qt.push(temp);
        return;
    }
    solution_using_recursion(qt);
    qt.push(temp);
}

void solve(queue<int> qt)
{
    solution_using_recursion(qt);

    cout << "reversed queue : ";
    while (!qt.empty())
    {
        cout << qt.front() << " ";
        qt.pop();
    }
    cout << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int n;
    cin >> n;
    queue<int> qt;

    for (int i = 0; i < n; i++)
    {
        qt.push(i + 1);
    }

    solution_using_stack(qt);
    solve(qt);
    return 0;
}