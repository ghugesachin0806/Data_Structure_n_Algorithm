#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> vect; // vector of string is defined
    cout << "Enter the total string - ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) // string input taken through 'temp' string variable
    {
        string temp;
        cin >> temp;
        vect.push_back(temp);
    }
    for (int i = 0; i < n; i++)    // string printed 
    {
        cout << vect[i] << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < vect[i].size(); j++)   // Every string's character is accessed here by indexing method
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Enter the total string - 5
// -> sachin
// -> soham
// -> kunal
// -> dhiraj
// -> kabir
// sachin
// soham
// kunal
// dhiraj
// kabir
// s a c h i n
// s o h a m
// k u n a l
// d h i r a j
// k a b i r