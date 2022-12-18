// adding n times 'a' in string ny two methods

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int n=10;
    // there are two methods
    for(int i=0;i<n;i++)
    {
        str=str+'a';   // here time complexity increases
    }
    for(int i=0;i<n;i++)
    {
        str.push_back('a');   // here time complexity is O(1)
    }
}