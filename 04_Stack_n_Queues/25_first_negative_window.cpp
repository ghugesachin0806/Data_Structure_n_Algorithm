// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include <bits/stdc++.h>
using namespace std;

vector<int> first_negative(vector<int> vect, int k)
{
    deque<int> temp;
    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        if (vect[i] < 0)
        {
            temp.push_back(i);
        }
    }

    if (temp.empty())
        ans.push_back(0);
    else
        ans.push_back(vect[temp.front()]);

    for (int i = k; i < vect.size(); i++)
    {
        if (!temp.empty() && i - temp.front() >= k)
        {
            temp.pop_front();
        }
        if (vect[i] < 0)
        {
            temp.push_back(i);
        }
        if (temp.empty())
            ans.push_back(0);
        else
        {
            ans.push_back(vect[temp.front()]);
        }
    }
    return ans;
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

    int k;
    cout << "window size : ";
    cin >> k;

    vector<int> sol;

    sol = first_negative(vect, k);

    cout << "given : ";
    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect[i] << " ";
    }
    cout << endl;

    cout << "solution : ";
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
    cout << endl;

    return 0;
}

// -> 8
// -> 12 -1 -7 8 -15 30 16 28
// -> window size : 3
// given : 12 -1 -7 8 -15 30 16 28
// solution : -1 -1 -7 -15 -15 0