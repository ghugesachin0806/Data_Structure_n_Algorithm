// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

#include <bits/stdc++.h>
using namespace std;

int solve_stack(vector<vector<int>> &vect)
{
    int total = vect.size();

    stack<int> st;
    // push all the elements in the stack
    for (int i = 0; i < total; i++)
    {
        st.push(i);
    }

    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        if (vect[a][b] == 1)
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }

    // remaining element is potential candidate for celebrity
    int candidate = st.top();

    // row checking
    bool row_check = false;
    int rw_cnt = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[candidate][i] == 0)
            rw_cnt++;
    }

    if (rw_cnt == vect.size())
        row_check = true;

    // col checking
    bool col_check = false;
    int col_cnt = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i][candidate] == 1)
            col_cnt++;
    }

    if (col_cnt == vect.size() - 1)
        col_check = true;

    ///////////////

    if (col_check == true && row_check == true)
        return st.top();

    else
        return -1;
}

int solve_bruteforce(vector<vector<int>> vect)
{
    int total = vect.size();
    int candidate = 0;

    for (int i = 1; i < vect.size(); i++)
    {
        if (vect[i][candidate] == 0)
            candidate = i;
    }

    // row checking
    bool row_check = false;
    int rw_cnt = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[candidate][i] == 0)
            rw_cnt++;
    }

    if (rw_cnt == vect.size())
        row_check = true;

    // col checking
    bool col_check = false;
    int col_cnt = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i][candidate] == 1)
            col_cnt++;
    }

    if (col_cnt == vect.size() - 1)
        col_check = true;

    ///////////////

    if (col_check == true && row_check == true)
        return candidate;

    else
        return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vect;

    for (int i = 0; i < n; i++)
    {
        vect.push_back(vector<int>());
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            vect[i].push_back(temp);
        }
    }

    cout << "the celebrity is : " << solve_bruteforce(vect) << endl;
    cout << "the celebrity is : " << solve_stack(vect) << endl;

    return 0;
}

// 4
// 0 1 0 0
// 0 0 0 0
// 1 1 1 1
// 1 1 1 1
// the celebrity is : 1  -> using bruteforce
// the celebrity is : 1   -> using stack