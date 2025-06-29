// https://leetcode.com/problems/longest-common-subsequence/

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index1, int index2, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (index1 < 0 || index2 < 0)
            return 0;

        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        if (text1[index1] == text2[index2])
        {
            dp[index1][index2] = 1 + solve(index1 - 1, index2 - 1, text1, text2, dp);
        }
        else
        {
            dp[index1][index2] = max(
                solve(index1 - 1, index2, text1, text2, dp),
                solve(index1, index2 - 1, text1, text2, dp));
        }
        return dp[index1][index2];
    }

    void collectAllLCS(int i, int j, string &text1, string &text2,
                       vector<vector<int>> &dp, string curr, set<string> &result)
    {
        if (i < 0 || j < 0)
        {
            reverse(curr.begin(), curr.end());
            result.insert(curr);
            return;
        }

        if (text1[i] == text2[j])
        {
            collectAllLCS(i - 1, j - 1, text1, text2, dp, curr + text1[i], result);
        }
        else
        {
            if (i > 0 && dp[i][j] == dp[i - 1][j])
                collectAllLCS(i - 1, j, text1, text2, dp, curr, result);
            if (j > 0 && dp[i][j] == dp[i][j - 1])
                collectAllLCS(i, j - 1, text1, text2, dp, curr, result);
        }
    }

    string getOneLCS(int i, int j, string &text1, string &text2, vector<vector<int>> &dp)
    {
        string lcs;
        while (i >= 0 && j >= 0)
        {
            if (text1[i] == text2[j])
            {
                lcs += text1[i];
                i--;
                j--;
            }
            else
            {
                if (i > 0 && dp[i][j] == dp[i - 1][j])
                    i--;
                else
                    j--;
            }
        }
        reverse(lcs.begin(), lcs.end());
        return lcs;
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int length = solve(n - 1, m - 1, text1, text2, dp);

        // 1. Print all LCS
        set<string> allLCS;
        collectAllLCS(n - 1, m - 1, text1, text2, dp, "", allLCS);

        cout << "All Longest Common Subsequences:\n";
        for (const auto &seq : allLCS)
        {
            cout << seq << endl;
        }

        // 2. Print one LCS
        string oneLCS = getOneLCS(n - 1, m - 1, text1, text2, dp);
        cout << "\nOne LCS: " << oneLCS << endl;

        return length;
    }
};



// Input
// text1 = "abcabcaa"
// text2 = "acbacba"

// Output
// All Longest Common Subsequences:
// ababa
// abaca
// abcba
// acaba
// acaca
// acbaa
// acbca

// One LCS: abcba
