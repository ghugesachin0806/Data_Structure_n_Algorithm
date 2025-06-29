class Solution {
public:
    // Top-down memoization for LCS
    int lcs(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = 1 + lcs(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = max(lcs(i - 1, j, s1, s2, dp), lcs(i, j - 1, s1, s2, dp));
    }

    string buildSCS(string &s1, string &s2, vector<vector<int>> &dp) {
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        string scs;

        while (i >= 0 && j >= 0) {
            if (s1[i] == s2[j]) {
                scs += s1[i];
                i--;
                j--;
            }
            else if (i > 0 && dp[i][j] == dp[i - 1][j]) {
                scs += s1[i];
                i--;
            } else {
                scs += s2[j];
                j--;
            }
        }

        while (i >= 0) scs += s1[i--];
        while (j >= 0) scs += s2[j--];

        reverse(scs.begin(), scs.end());
        return scs;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        // dp[i][j] stores LCS of str1[0..i] and str2[0..j]
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // fill dp table using top-down recursion
        lcs(n - 1, m - 1, str1, str2, dp);

        // reconstruct SCS from dp
        return buildSCS(str1, str2, dp);
    }
};
