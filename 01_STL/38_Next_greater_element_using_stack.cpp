// https://www.hackerrank.com/contests/second/challenges/next-greater-element/problem#:~:text=The%20Next%20greater%20Element%20for,each%20element%20are%20as%20follows.

// Next greater element
#include <bits/stdc++.h>
using namespace std;

vector<int> nge(vector<int> vect2)
{
    vector<int> ret(vect2.size());
    stack<int> st;
    for (int i = 0; i < vect2.size(); i++)
    {
        while (!st.empty() && vect2[st.top()] < vect2[i])
        {
            ret[st.top()] = vect2[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        ret[st.top()] = -1;
        st.pop();
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vect(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vect[i];
    }
    vector<int> fin = nge(vect);

    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect[i] << " " << fin[i] << endl;
    }
}

// - - > 8
// -> 12
// -> 2
// -> 16
// -> 10
// -> 9
// -> 11
// -> 16
// -> 14
// 12 16
// 2 16
// 16 -1
// 10 11
// 9 11
// 11 16
// 16 -1
// 14 -1