// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////// optimized solution///////////////////////////////////
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

void solution(vector<int> vect)
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

    cout << "max area by optimized : " << area << endl;
}

/////////////////////////////// brute force solution /////////////////////////////////

void brute_force(vector<int> vect)
{
    int area = 0;
    int cnt = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        if (cnt < vect[i])
            cnt = vect[i];

        int left = i;
        int right = i;

        int left_cnt = 0;
        int right_cnt = 1;

        while (left != 0)
        {
            left--;
            if (vect[left] >= vect[i])
            {
                left_cnt++;
            }
            else
                break;
        }

        while (right != vect.size() - 1)
        {
            right++;
            if (vect[right] >= vect[i])
            {
                right_cnt++;
            }
            else
                break;
        }

        int temp_area = vect[i] * (left_cnt + right_cnt);

        if (area < temp_area)
        {
            area = temp_area;
        }
    }

    if (cnt > area)
        area = cnt;

    cout << "max area by brute_force : " << area << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vect;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vect.push_back(temp);
    }

    brute_force(vect);

    solution(vect);
}

// -> 6
// -> 2 1 4 6 4 5
// max area is by brute_force : 16
// max area by optimized : 16