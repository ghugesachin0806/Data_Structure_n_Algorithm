
class Solution {
  public:
    int solve(int index1, int index2, int count, string &s1, string &s2, vector<vector<vector<int>>> &dp) {
        if (index1 < 0 || index2 < 0)
            return count;

        if (dp[index1][index2][count] != -1)
            return dp[index1][index2][count];

        int temp = count;

        if (s1[index1] == s2[index2]) {
            temp = solve(index1 - 1, index2 - 1, count + 1, s1, s2, dp);
        }

        int move1 = solve(index1 - 1, index2, 0, s1, s2, dp);
        int move2 = solve(index1, index2 - 1, 0, s1, s2, dp);

        return dp[index1][index2][count] = max(temp, max(move1, move2));
    }

    int longestCommonSubstr(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();

        // 3D dp for (i, j, count)
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(min(n, m) + 1, -1)));

        return solve(n - 1, m - 1, 0, s1, s2, dp);
    }
};
