// https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void soln(int index, int cnt, int &ans, vector<int> indegree, vector<vector<int>> &requests)
    {
        if (index == requests.size())
        {
            for (int i = 0; i < indegree.size(); i++)
            {
                if (indegree[i] != 0)
                    return;
            }
            ans = max(ans, cnt);
            return;
        }

        // exclude call
        soln(index + 1, cnt, ans, indegree, requests);
        // include call
        indegree[requests[index][0]]++;
        indegree[requests[index][1]]--;
        soln(index + 1, cnt + 1, ans, indegree, requests);
    }
    int maximumRequests(int n, vector<vector<int>> &requests)
    {

        int ans = 0;
        int cnt = 0;
        int index = 0;
        vector<int> indegree(n, 0);
        soln(index, cnt, ans, indegree, requests);

        return ans;
    }
};