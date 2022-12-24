// https://practice.geeksforgeeks.org/problems/max-rectangle/1

#include <bits/stdc++.h>
using namespace std;
vector<int> next_small(vector<int> vect)
{
    vector<int> temp(vect.size());
    stack<int> st;
    st.push(vect.size());

    for (int i = vect.size() - 1; i >= 0; i--)
    {
        while (st.top() != vect.size() && vect[st.top()] >= vect[i])
        {
            st.pop();
        }
        temp[i] = st.top();
        st.push(i);
    }

    return temp;
}

vector<int> prev_small(vector<int> vect)
{
    vector<int> temp(vect.size());
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < vect.size(); i++)
    {
        while (st.top() != -1 && vect[st.top()] >= vect[i])
        {
            st.pop();
        }
        temp[i] = st.top();
        st.push(i);
    }

    return temp;
}

int area_rect(vector<int> vect)
{
    vector<int> nxt(vect.size());
    vector<int> prev(vect.size());

    nxt = next_small(vect);
    prev = prev_small(vect);

    int area = INT_MIN;
    for (int i = 0; i < vect.size(); i++)
    {
        int h = vect[i];
        int b = nxt[i] - prev[i] - 1;

        int temp_area = h * b;

        area = max(area, temp_area);
    }

    return area;
}

int soln(vector<vector<int>> &vect)
{
    vector<int> temp(vect.size()); // The default value of a vector is 0
    int area = INT_MIN;
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect.size(); j++)
        {
            if (vect[i][j] == 1)
                temp[j]++;
            else
                temp[j] = 0;
        }

        int temp_area;
        temp_area = area_rect(temp);
        if (temp_area > area)
            area = temp_area;
    }

    return area;
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

    cout << "Max Area matrix : " << soln(vect) << endl;

    return 0;
}

// -> 4
// -> 0 1 1 0
// -> 1 1 1 1
// -> 1 1 1 1
// -> 1 1 1 0
// Max Area matrix : 9

// -> 4
// -> 0 1 1 0
// -> 1 1 1 1
// -> 1 1 1 1
// -> 1 1 0 0
// Max Area matrix : 8