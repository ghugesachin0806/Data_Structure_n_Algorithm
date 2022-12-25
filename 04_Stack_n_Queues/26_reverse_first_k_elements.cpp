// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

#include <bits/stdc++.h>
using namespace std;
void solution_using_stack(queue<int> qt, int temp)
{
    stack<int> st;
    int k = temp;
    int n = qt.size() - temp;
    while (k--)
    {
        st.push(qt.front());
        qt.pop();
    }

    while (!st.empty())
    {
        qt.push(st.top());
        st.pop();
    }

    while (n--)
    {
        qt.push(qt.front());
        qt.pop();
    }

    cout << "reversed queue : ";
    while (!qt.empty())
    {
        cout << qt.front() << " ";
        qt.pop();
    }
    cout << endl;
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
    cout << "enter the k value : ";
    int k;
    cin >> k;

    solution_using_stack(qt, k);
    return 0;
}

// 7
// enter the k value : 4
// reversed queue : 4 3 2 1 5 6 7