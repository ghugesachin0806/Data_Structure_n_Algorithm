// https://leetcode.com/problems/edit-distance/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index1, int index2, string &word1, string &word2, vector<vector<int>> &dp)
    {
        if (index1 < 0)
            return index2 + 1; // Remaining Insertion
        if (index2 < 0)
            return index1 + 1; // Remaining Deletion

        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        if (word1[index1] == word2[index2])
            return solve(index1 - 1, index2 - 1, word1, word2, dp);

        // Replace
        int temp1 = 1 + solve(index1 - 1, index2 - 1, word1, word2, dp);
        // Delete
        int temp2 = 1 + solve(index1 - 1, index2, word1, word2, dp);
        // Insert
        int temp3 = 1 + solve(index1, index2 - 1, word1, word2, dp);

        return dp[index1][index2] = min(temp1, min(temp2, temp3));
    }
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));

        return solve(word1.size() - 1, word2.size() - 1, word1, word2, dp);
    }
};