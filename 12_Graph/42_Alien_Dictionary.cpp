// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findOrder(string dict[], int N, int K)
    {
        // code here
        vector<int> adj[K];

        for (int i = 0; i < N - 1; i++)
        {
            string str1 = dict[i];
            string str2 = dict[i + 1];

            int min_len = min(str1.size(), str2.size());

            for (int j = 0; j < min_len; j++)
            {
                if (str1[j] != str2[j])
                {
                    adj[str1[j] - 'a'].push_back(str2[j] - 'a');
                    break;
                }
            }
        }

        vector<int> indegree(K, 0);

        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
                indegree[adj[i][j]]++;
        }

        vector<int> ans;
        queue<int> qt;

        for (int i = 0; i < K; i++)
        {
            if (indegree[i] == 0)
                qt.push(i);
        }

        while (!qt.empty())
        {
            int temp = qt.front();
            qt.pop();
            ans.push_back(temp);

            for (int i = 0; i < adj[temp].size(); i++)
            {
                indegree[adj[temp][i]]--;
                if (indegree[adj[temp][i]] == 0)
                    qt.push(adj[temp][i]);
            }
        }

        string final_string="";

        for(int i=0;i<ans.size();i++)
        {
            final_string.push_back(char(ans[i]+'a'));
        }

        return final_string;

    }
};