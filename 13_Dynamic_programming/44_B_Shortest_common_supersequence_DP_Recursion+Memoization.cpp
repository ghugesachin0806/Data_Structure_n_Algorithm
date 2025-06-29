class Solution {
public:
    // Memoized function to compute length of shortest common supersequence
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j]) {
            dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);
        } else {
            dp[i][j] = 1 + min(
                solve(i - 1, j, s1, s2, dp),
                solve(i, j - 1, s1, s2, dp)
            );
        }
        return dp[i][j];
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        solve(n - 1, m - 1, str1, str2, dp);  // fill the dp table

        // Reconstruct the SCS string from dp table
        string scs;
        int i = n - 1, j = m - 1;
        while (i >= 0 && j >= 0) {
            if (str1[i] == str2[j]) {
                scs += str1[i];
                i--;
                j--;
            } else {
                if (i > 0 && (j < 0 || dp[i][j] == 1 + dp[i - 1][j])) {
                    scs += str1[i];
                    i--;
                } else {
                    scs += str2[j];
                    j--;
                }
            }
        }

        while (i >= 0) {
            scs += str1[i];
            i--;
        }
        while (j >= 0) {
            scs += str2[j];
            j--;
        }

        reverse(scs.begin(), scs.end());
        return scs;
    }
};
