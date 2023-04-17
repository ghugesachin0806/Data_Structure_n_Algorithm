// https://practice.geeksforgeeks.org/problems/word-ladder-ii/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int differ(string str1, string str2)
    {
        int cnt = 0;
        for (int i = 0; i < str1.length(); i++)
        {
            if (str1[i] != str2[i])
                cnt++;
        }
        return cnt;
    }

public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {
        // code here
        unordered_map<string, vector<string>> adj_list;

        int cmt = 0;
        vector<string> new_wordList = wordList;
        for (int i = 0; i < wordList.size(); i++)
        {
            if (wordList[i] == beginWord)
                cmt++;
        }

        if (cmt == 0)
            new_wordList.push_back(beginWord);

        for (int i = 0; i < new_wordList.size() - 1; i++)
        {
            for (int j = i + 1; j < new_wordList.size(); j++)
            {
                if (differ(new_wordList[i], new_wordList[j]) == 1)
                {
                    adj_list[new_wordList[i]].push_back(new_wordList[j]);
                    adj_list[new_wordList[j]].push_back(new_wordList[i]);
                }
            }
        }

        bool flag = false;
        unordered_map<string, bool> visited;
        unordered_map<string, bool> inner_visited;
        queue<stack<string>> qt;
        stack<string> st;
        stack<string> empty_st;
        queue<stack<string>> inner_qt;
        st.push(beginWord);
        qt.push(st);
        qt.push(empty_st);
        visited[beginWord] = true;

        while (!qt.empty())
        {
            stack<string> temp = qt.front();
            qt.pop();

            if (temp.size() == 0)
            {

                while (!inner_qt.empty())
                {
                    qt.push(inner_qt.front());
                    inner_qt.pop();
                }

                if (flag)
                    break;

                if (!qt.empty())
                    qt.push(temp);

                for (auto it : inner_visited)
                {
                    visited[it.first] = true;
                }

                inner_visited.clear();

                continue;
            }

            for (auto it : adj_list[temp.top()])
            {
                if (!visited[it])
                {
                    if (it == endWord)
                        flag = true;
                    stack<string> new_st = temp;
                    new_st.push(it);
                    inner_qt.push(new_st);
                    inner_visited[it] = true;
                }
            }
        }

        vector<vector<string>> ans;

        while (!qt.empty())
        {
            stack<string> temp = qt.front();
            qt.pop();

            if (temp.top() == endWord)
            {
                vector<string> vect;
                while (!temp.empty())
                {
                    vect.push_back(temp.top());
                    temp.pop();
                }
                reverse(vect.begin(), vect.end());
                ans.push_back(vect);
            }
        }

        return ans;
    }
};