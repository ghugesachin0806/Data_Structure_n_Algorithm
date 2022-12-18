// https://leetcode.com/problems/subsets/

// Subsets in recursion

#include <bits/stdc++.h>
using namespace std;

void subset(vector<vector<int>> &ans, vector<int> output, vector<int> num, int index)
{
    // Base case
    if (index >= num.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude
    subset(ans, output, num, index + 1);

    // include
    int free = num[index];
    output.push_back(free);

    subset(ans, output, num, index + 1);
}

vector<vector<int>> solve(vector<int> &num)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;

    subset(ans, output, num, index);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vect;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vect.push_back(m);
    }
    vector<vector<int>> ans;

    ans = solve(vect);

    cout << "{ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ",";
        }
        cout << " ],";
    }
    cout << " }";
}

// -> 3
// -> 1 2 3
// { [  ],[ 3, ],[ 2, ],[ 2,3, ],[ 1, ],[ 1,3, ],[ 1,2, ],[ 1,2,3, ], }