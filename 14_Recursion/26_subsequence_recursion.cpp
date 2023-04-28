// https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087

// Subsequence in recursion

#include <bits/stdc++.h>
using namespace std;

void solve(int index, string temp, string &str, vector<string> &ans)
{
    if (index >= str.size())
    {
        if (temp.size() != 0)
            ans.push_back(temp);
        return;
    }

    // Exclude call
    solve(index + 1, temp, str, ans);

    // Include call
    temp.push_back(str[index]);
    solve(index + 1, temp, str, ans);
}
vector<string> subsequences(string str)
{
    // Write your code here

    int index = 0;
    string temp = "";
    vector<string> ans;

    solve(index, temp, str, ans);

    return ans;
}
