// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

#include <bits/stdc++.h>
using namespace std;

void solve(string str)
{
    queue<char> qt;
    unordered_map<char, int> cnt;

    for (int i = 0; i < str.length(); i++)
    {
        cnt[str[i]]++;

        if (cnt[str[i]] == 1)
        {
            qt.push(str[i]);
        }

        while (!qt.empty() && cnt[qt.front()] != 1)
        {
            qt.pop();
        }
        if (qt.empty())
            cout << "#";
        else
            cout << qt.front();
    }
    cout << endl;
}

int main()
{
    string str;
    cin >> str;
    solve(str);
    return 0;
}

// -> aabcdbc
// a#bbbcd