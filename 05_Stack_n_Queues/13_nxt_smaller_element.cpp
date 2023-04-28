// https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &vect)
{
    vector<int> temp(vect.size());
    stack<int> st;
    st.push(-1);

    for (int i = vect.size() - 1; i >= 0; i--)
    {
        while (st.top() >= vect[i])
        {
            st.pop();
        }
        temp[i] = st.top();
        st.push(vect[i]);
    }

    cout << "next : ";
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vect;
    cout << "Now  : ";
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        vect.push_back(k);
    }

    solve(vect);
    return 0;
}

// -> 6
// -> Now  : 6 9 3 4 2 1
// next : 3 3 2 2 1 -1