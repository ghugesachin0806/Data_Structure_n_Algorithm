// https://practice.geeksforgeeks.org/problems/lower-case-to-upper-case3410/1

#include <bits/stdc++.h>
using namespace std;

string to_upper(string str)
{
    // code
    string ans = "";

    for (int i = 0; i < str.size(); i++)
    {
        char temp = (str[i] & '_' );
        ans.push_back(temp);
    }

    return ans;
}