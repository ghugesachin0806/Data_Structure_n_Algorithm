// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

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
            return max(solve(index1, index2 - 1, str1, str2), solve(index1 - 1, index2, str1, str2));
        }
    }
    int minOperations(string str1, string str2)
    {
        // Your code goes here
        int sub_length = solve(str1.size() - 1, str2.size() - 1, str1, str2);

        int min_op = (str1.size() - sub_length) + (str2.size() - sub_length);

        return min_op;
    }
};