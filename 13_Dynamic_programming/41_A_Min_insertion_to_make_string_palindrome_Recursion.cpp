// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index1, int index2, string &str1, string &str2)
    {
        if (index1 < 0 || index2 < 0)
            return 0;

        if (str1[index1] == str2[index2])
        {
            return 1 + solve(index1 - 1, index2 - 1, str1, str2);
        }
        else
        {
            return max(solve(index1 - 1, index2, str1, str2), solve(index1, index2 - 1, str1, str2));
        }
    }
    int minInsertions(string s)
    {
        string straight = s;
        string reverse;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            reverse.push_back(s[i]);
        }

        int temp = solve(straight.size() - 1, reverse.size() - 1, straight, reverse);

        int length = s.size();

        return length - temp;
    }
};