// https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    set<string> st;

    int solve_length(int index1, int index2, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (index1 < 0 || index2 < 0)
            return 0;

        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        if (text1[index1] == text2[index2])
        {
            dp[index1][index2] = 1 + solve_length(index1 - 1, index2 - 1, text1, text2, dp);
            return dp[index1][index2];
        }

        dp[index1][index2] = max(solve_length(index1 - 1, index2, text1, text2, dp), solve_length(index1, index2 - 1, text1, text2, dp));
        return dp[index1][index2];
    }

    // void solve_tle(int index1, int index2, string &text1, string &text2, int length, string temp, vector<string> &res)
    // {
    //     if (length == 0)
    //     {
    //         if (st.find(temp) == st.end())
    //         {
    //             st.insert(temp);
    //             res.push_back(temp);
    //         }
    //         return;
    //     }

    //     if (index1 == text1.size() || index2 == text2.size())
    //         return;

    //     if (text1[index1] == text2[index2])
    //     {
    //         temp.push_back(text1[index1]);
    //         solve_tle(index1 + 1, index2 + 1, text1, text2, length - 1, temp, res);
    //     }
    //     else
    //     {
    //         solve_tle(index1, index2 + 1, text1, text2, length, temp, res);
    //         solve_tle(index1 + 1, index2, text1, text2, length, temp, res);
    //     }
    // }

    void solve_optimized(int index1, int index2, string &text1, string &text2, int length, string temp, vector<string> &res)
    {
        if (length == 0)
        {
            if (st.find(temp) == st.end())
            {
                st.insert(temp);
                res.push_back(temp);
            }
            return;
        }

        for (int t1 = index1; t1 < text1.size(); t1++)
        {
            for (int t2 = index2; t2 < text2.size(); t2++)
            {
                if (text1[t1] == text2[t2])
                {
                    temp.push_back(text1[t1]);
                    solve_optimized(t1 + 1, t2 + 1, text1, text2, length - 1, temp, res);
                    temp.pop_back();
                }
            }
        }
    }

    vector<string> all_longest_common_subsequences(string s, string t)
    {
        // Code here
        int index1 = s.size() - 1;
        int index2 = t.size() - 1;

        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));

        int length = solve_length(index1, index2, s, t, dp);

        string temp = "";
        vector<string> res;

        // solve_tle(0, 0, s, t, length, temp, res);
        solve_optimized(0, 0, s, t, length, temp, res);

        sort(res.begin(), res.end());

        return res;
    }
};
