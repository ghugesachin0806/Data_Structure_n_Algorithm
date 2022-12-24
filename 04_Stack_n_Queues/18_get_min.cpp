// https://www.codingninjas.com/codestudio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465?topList=love-babbar-dsa-sheet-problems

// solve the question by time complexity -> O(1) & space complexity -> O(1)

#include <bits/stdc++.h>
using namespace std;

// Here min element solved in O(1) time complexity and O(1) space complexity
void solve(vector<int> vect)
{
    stack<int> st;
    int temp = vect[0];
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i] < temp)
        {
            int curr = 2 * vect[i] - temp;
            st.push(curr);
            temp = vect[i];
        }
        else
        {
            st.push(vect[i]);
        }
    }

    cout << "values in stacks are : ";
    for (int i = vect.size() - 1; i >= 0; i--)
    {
        cout << vect[i] << " ";
    }
    cout << endl;

    cout << "Min element of stack : ";

    while (!st.empty())
    {
        if (st.top() < temp)
        {
            cout << temp << " ";
            temp = 2 * temp - st.top();
            st.pop();
        }
        else
        {
            cout << temp << " ";
            st.pop();
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vect;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vect.push_back(x);
    }

    solve(vect);
    return 0;
}

// -> 10
// -> 7 9 8 6 9 8 7 2 9 8
// values in stacks are : 8 9 2 7 8 9 6 8 9 7
// Min element of stack : 2 2 2 6 6 6 6 7 7 7