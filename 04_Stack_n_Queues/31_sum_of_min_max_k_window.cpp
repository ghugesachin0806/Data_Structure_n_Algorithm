// https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &vect, int k)
{
    deque<int> max;
    deque<int> min;
    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        while (!max.empty() && vect[max.back()] <= vect[i])
        {
            max.pop_back();
        }
        while (!min.empty() && vect[min.back()] >= vect[i])
        {
            min.pop_back();
        }

        max.push_back(i);
        min.push_back(i);
    }

    ans.push_back(vect[max.front()] + vect[min.front()]);

    for (int i = k; i < vect.size(); i++)
    {
        if (i - max.front() >= k)
        {
            max.pop_front();
        }
        if (i - min.front() >= k)
        {
            min.pop_front();
        }

        while (!max.empty() && vect[max.back()] <= vect[i])
        {
            max.pop_back();
        }
        while (!min.empty() && vect[min.back()] >= vect[i])
        {
            min.pop_back();
        }

        max.push_back(i);
        min.push_back(i);

        ans.push_back(vect[max.front()] + vect[min.front()]);
    }

    cout << "ans : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
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
    cin >> k;

    solve(vect, k);
    return 0;
}

// -> 7
// -> 2 5 -1 7 -3 -1 -2
// -> 4
// ans : 6 4 4 4

// -> 7
// -> -3 2 5 -1 7 -1 -2
// -> 3
// ans : 2 4 6 6 5