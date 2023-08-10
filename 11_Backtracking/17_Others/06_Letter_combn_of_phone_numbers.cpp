// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void soln(int index, string str, vector<int> &digit, vector<string> &mt, vector<string> &ans)
    {
        if (index == digit.size())
        {
            if (!str.empty())
                ans.push_back(str);
            return;
        }

        for (int i = 0; i < mt[digit[index]].size(); i++)
        {
            str.push_back(mt[digit[index]][i]);
            soln(index + 1, str, digit, mt, ans);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {

        vector<string> mt = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<int> digit;

        for (int i = 0; i < digits.size(); i++)
        {
            digit.push_back(digits[i] - 48);
        }

        vector<string> ans;
        string str = "";

        soln(0, str, digit, mt, ans);

        return ans;
    }
};