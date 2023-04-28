// https://leetcode.com/problems/reorganize-string/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reorganizeString(string s)
    {
        string str = "";
        map<char, int> mt;
        priority_queue<pair<int, char>> qt;

        for (auto temp : s)
            mt[temp] += 1;

        for (auto temp : mt)
            qt.push(make_pair(temp.second, temp.first));

        while (qt.size() > 1)
        {
            auto temp1 = qt.top();
            qt.pop();
            auto temp2 = qt.top();
            qt.pop();

            str += temp1.second;
            str += temp2.second;

            temp1.first--;
            temp2.first--;

            if (temp1.first)
                qt.push(temp1);
            if (temp2.first)
                qt.push(temp2);
        }

        if (!qt.empty())
        {
            if (qt.top().first > 1)
                return "";
            else
            {
                str += qt.top().second;
                return str;
            }
        }
        else
        {
            return str;
        }
    }
};