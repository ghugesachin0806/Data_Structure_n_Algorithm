#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> vect = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

    vector<pair<int, int>>::iterator it;

    //////////////////////////////////////////////////////////////////////////////////////////
    cout << "First method of printing elements of pairs - " << endl;

    for (it = vect.begin(); it != vect.end(); it++)               // here 'it' iterator points to vector not its elements  
    {
        cout << (*it).first << " " << (*it).second << endl;       // we have to use first and second keyword to access the elements of pairs
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Second method of printing elements of pairs - " << endl;   // This method is commonly used ro print the elements of pairs

    for (it = vect.begin(); it != vect.end(); it++)
    {
        cout << it->first << " " << it->second << endl; 
    }
    return 0;
}

// First method of printing elements of pairs -  
// 1 2
// 3 4
// 5 6
// 7 8
// Second method of printing elements of pairs - 
// 1 2
// 3 4
// 5 6
// 7 8