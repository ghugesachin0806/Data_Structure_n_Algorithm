// https://leetcode.com/problems/longest-common-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index1, int index2, string &text1, string &text2)
    {
        if (index1 < 0 || index2 < 0)
            return 0;

        if (text1[index1] == text2[index2])
        {
            int temp = 1 + solve(index1 - 1, index2 - 1, text1, text2);
            return temp;
        }

        return max(solve(index1 - 1, index2, text1, text2), solve(index1, index2 - 1, text1, text2));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int index1 = text1.size() - 1;
        int index2 = text2.size() - 1;
        return solve(index1, index2, text1, text2);
    }
};