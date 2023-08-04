// https://leetcode.com/problems/word-break/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool soln(int index, string &str, unordered_set<string> &st, vector<int> &dp)
    {
        if (index == str.size())
            return true;

        if (dp[index] != -1)
            return dp[index];

        string t = "";
        for (int i = index; i < str.size(); i++)
        {
            if (st.find(str.substr(index, i - index + 1)) != st.end() && soln(i + 1, str, st, dp))
                return dp[index] = true;
        }

        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {

        vector<int> dp(s.size(), -1);

        unordered_set<string> st;
        for (auto it : wordDict)
        {
            st.insert(it);
        }
        int index = 0;

        return soln(index, s, st, dp);
    }
};