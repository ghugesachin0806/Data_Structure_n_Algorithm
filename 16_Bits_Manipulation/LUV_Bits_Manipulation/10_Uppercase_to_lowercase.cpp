// https://leetcode.com/problems/to-lower-case/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string toLowerCase(string s)
    {
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            char temp = s[i];
            if (temp > 64 && temp < 91)
                temp = (s[i] | ' ');
            ans.push_back(temp);
        }

        return ans;
    }
};