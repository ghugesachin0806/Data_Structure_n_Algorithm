// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
using namespace std;

bool issafe(vector<vector<int>> &vect, vector<vector<int>> visit, int x, int y)
{
    if ((x >= 0 && x < vect.size()) && (y >= 0 && y < vect.size()) && (visit[x][y] == 0) && (vect[x][y] == 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void maze(vector<vector<int>> &vect, vector<vector<int>> visit, vector<string> &ans, string s, int x, int y)
{
    // Base case
    if (x == (vect.size() - 1) && y == (vect.size() - 1))
    {
        ans.push_back(s);
        return;
    }

    visit[x][y] = 1;

    // down
    int newx = x + 1;
    int newy = y;
    if (issafe(vect, visit, newx, newy))
    {
        s.push_back('D');
        maze(vect, visit, ans, s, newx, newy);
        s.pop_back();
    }

    // right
    newx = x;
    newy = y + 1;
    if (issafe(vect, visit, newx, newy))
    {
        s.push_back('R');
        maze(vect, visit, ans, s, newx, newy);
        s.pop_back();
    }

    // left
    newx = x;
    newy = y - 1;
    if (issafe(vect, visit, newx, newy))
    {
        s.push_back('L');
        maze(vect, visit, ans, s, newx, newy);
        s.pop_back();
    }

    // up
    newx = x - 1;
    newy = y;
    if (issafe(vect, visit, newx, newy))
    {
        s.push_back('U');
        maze(vect, visit, ans, s, newx, newy);
        s.pop_back();
    }
}

vector<string> solve(vector<vector<int>> &vem)
{
    vector<string> ans;

    if (vem[0][0] == 0)
    {
        return ans;
    }

    vector<vector<int>> visit = vem;

    for (int i = 0; i < vem.size(); i++)
    {
        for (int j = 0; j < vem.size(); j++)
        {
            visit[i][j] = 0;
        }
    }
    string s = "";
    maze(vem, visit, ans, s, 0, 0);

    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vect;
    for (int i = 0; i < n; i++)
    {
        vect.push_back(vector<int>());
        for (int j = 0; j < n; j++)
        {
            int m;
            cin >> m;
            vect[i].push_back(m);
        }
    }

    vector<string> str;

    str = solve(vect);

    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << endl;
    }
}

// -> 4
// -> 1 1 1 1
// -> 1 0 0 1
// -> 1 0 0 1
// -> 1 1 1 1
// DDDRRR
// RRRDDD