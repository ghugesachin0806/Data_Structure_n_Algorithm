// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<int>> &m, vector<vector<int>> &visited, vector<string> &vect, string &str, int x, int y)
    {
        if (x == m.size() - 1 && y == m.size() - 1)
        {
            vect.push_back(str);
            visited[y][x] = 0;
            str.pop_back();
            return;
        }

        if (y + 1 < m.size() && m[y + 1][x] == 1 && visited[y + 1][x] == 0)
        {
            str.push_back('D');
            visited[y + 1][x] = 1;
            solve(m, visited, vect, str, x, y + 1);
        }
        if (x - 1 >= 0 && m[y][x - 1] == 1 && visited[y][x - 1] == 0)
        {
            str.push_back('L');
            visited[y][x - 1] = 1;
            solve(m, visited, vect, str, x - 1, y);
        }
        if (x + 1 < m.size() && m[y][x + 1] == 1 && visited[y][x + 1] == 0)
        {
            str.push_back('R');
            visited[y][x + 1] = 1;
            solve(m, visited, vect, str, x + 1, y);
        }
        if (y - 1 >= 0 && m[y - 1][x] == 1 && visited[y - 1][x] == 0)
        {
            str.push_back('U');
            visited[y - 1][x] = 1;
            solve(m, visited, vect, str, x, y - 1);
        }

        visited[y][x] = 0;
        str.pop_back();
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> vect;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        string str = "";

        if (m[0][0] == 1)
        {
            visited[0][0] = 1;
            solve(m, visited, vect, str, 0, 0);
        }
        if (vect.size() == 0)
            vect.push_back("-1");

        return vect;
    }
};