// https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int cnt(stack<char> &st)
{
    int cnt1 = 0;
    int cnt2 = 0;
    while (!st.empty())
    {
        if (st.top() == '{')
            cnt1++;
        else
            cnt2++;

        st.pop();
    }
    int total = ((cnt1 + 1) / 2) + ((cnt2 + 1) / 2);

    return total;
}

int valid(string str)
{
    if (str.length() % 2 == 1)
    {
        cout << "Invalid " << endl;
        return -1;
    }

    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{' || st.empty())
        {
            st.push(str[i]);
        }
        else
        {
            if (st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(str[i]);
            }
        }
    }

    if (st.empty())
    {
        return 0;
    }
    else
    {
        int t = cnt(st);
        return t;
    }
}

int main()
{
    string str;
    cin >> str;

    cout << "value : " << valid(str) << endl;

    return 0;
}

// {{{}{{{
// value : Invalid
// -1

// {{{{
// value : 2

// }}}}
// value : 2

// {{{}{{
// value : 2