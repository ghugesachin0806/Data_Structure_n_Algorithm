// https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_16

// Subsequence in recursion

#include <bits/stdc++.h>
using namespace std;

void street(vector<string> &ans, string str, string output, int index)
{
    // Base case
    if (index >= str.size())
    {
        ans.push_back(output);
        return;
    }
    
    // Exclude
    street(ans, str, output, index + 1);

    // Include
    output.push_back(str[index]);
    street(ans, str, output, index + 1);
}

vector<string> solve(string str)
{
    vector<string> ans;
    int index = 0;
    string output;

    street(ans, str, output, index);
    return ans;
}

int main()
{
    string str;
    cin >> str;
    vector<string> strong;

    strong = solve(str);

    cout << strong.size() << endl;

    for (int i = 0; i < strong.size(); i++)
    {
        cout << strong[i] << " ";
    }
}

// -> abc
// 8
//  c b bc a ac ab abc