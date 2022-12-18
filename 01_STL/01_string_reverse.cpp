#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    string str_rev;
    // don't use following code , because it adding char to string
    // for (int i = str.size() - 1; i >= 0; --i)
    // {
    //     str_rev = str_rev + str[i];
    // }
    for(int i=str.size()-1;i>=0;--i)
    {
        str_rev.push_back(str[i]);//it pushing back char by char into string
    }
    cout<<str_rev<<endl;
    return 0;
}