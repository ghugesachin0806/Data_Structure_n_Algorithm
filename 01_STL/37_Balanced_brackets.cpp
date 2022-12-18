// https://www.hackerrank.com/challenges/balanced-brackets/problem
// Balanced Brackets
#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> symbol = {{'[', -1}, {'{', -2}, {'(', -3}, {')', 3}, {'}', 2}, {']', 1}}; // Global map
string balanced(string str)
{
    stack<char> sp;
    for (char tp : str)
    {
        if (symbol[tp] < 0)
        {
            sp.push(tp);
        }
        else
        {
            if (sp.empty())
            {
                return "NO";
            }
            char top = sp.top();
            sp.pop();

            if (symbol[top] + symbol[tp] != 0)
            {
                return "NO";
            }
        }
    }
    if (sp.empty())
    {
        return "YES";
    }
    return "NO";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << balanced(s) << endl;
    }
}
// -> 3
// -> {{{}}}{{}}(())({})
// YES
// -> {{{(())}}}[[[
// NO
// -> ]]]][[[[{{{}}}
// NO