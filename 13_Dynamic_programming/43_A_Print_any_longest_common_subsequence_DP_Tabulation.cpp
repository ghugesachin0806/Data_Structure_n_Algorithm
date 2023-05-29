// https://www.youtube.com/watch?v=-zI4mrF2Pb4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=28&ab_channel=takeUforward

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonSubsequence(string text1, string text2)
    {
        // create a tabulation first

        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for (int i = 1; i <= text1.size(); i++)
        {
            for (int j = 1; j <= text2.size(); j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int max_length_str = dp[text1.size()][text2.size()];

        // Tracking the tabulation for extract the subsequence

        int i = text1.size();
        int j = text2.size();

        string str;

        while (i > 0 && j > 0)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                str.push_back(text1[i - 1]);
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }

        reverse(str.begin(), str.end());

        return str;
    }
};

int main()
{
    Solution s1;
    cout << s1.longestCommonSubsequence("abcadb", "bcacdhb") << endl;
}

// bcadb