// https://practice.geeksforgeeks.org/problems/word-ladder/1

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
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        // Code here
        unordered_map<string, vector<string>> adj_list;

        int cmt = 0;
        vector<string> new_wordList = wordList;
        for (int i = 0; i < wordList.size(); i++)
        {
            if (wordList[i] == startWord)
                cmt++;
        }

        if (cmt == 0)
            new_wordList.push_back(startWord);

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

        int cnt = 0;
        int ans = 0;
        queue<string> qt;
        unordered_map<string, bool> visited;

        string empty_string = "";
        qt.push(startWord);
        qt.push(empty_string);
        visited[startWord] = true;

        while (!qt.empty())
        {
            string temp = qt.front();
            qt.pop();

            if (temp == targetWord)
            {
                cnt++;
                ans = cnt;
                break;
            }

            if (temp == empty_string)
            {
                cnt++;
                if (!qt.empty())
                    qt.push(empty_string);

                continue;
            }

            for (auto it : adj_list[temp])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    qt.push(it);
                }
            }
        }
        return ans;
    }
};