// https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

bool match(char curr, char next)
{
    if (curr == '(' && next == ')' || curr == '[' && next == ']' || curr == '{' && next == '}')
        return true;
    else
        return false;
}

bool solve(string str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            st.push(str[i]);
        }
        else if (st.empty())
        {
            return false;
        }
        else
        {
            if (match(st.top(), str[i]))
            {
                st.pop();
            }
            else
                return false;
        }
    }

    if (st.empty())
        return true;
    else
        return false;
}

int main()
{
    string str;
    cin >> str;

    if (solve(str))
    {
        cout << "balanced !" << endl;
    }
    else
    {
        cout << "unbalanced !" << endl;
    }
    return 0;
}

// -> ()()()()()({[]})
// balanced !

// ->((((((((((((((((
// unbalanced !

// {[{[}]}]
// unbalanced !